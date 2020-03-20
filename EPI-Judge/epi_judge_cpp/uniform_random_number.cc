#include <functional>
#include <random>
#include <vector>
#include <iostream>
#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/random_sequence_checker.h"
#include "test_framework/timed_executor.h"
using std::bind;
using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

int ZeroOneRandom() {
  default_random_engine gen((random_device())());
  uniform_int_distribution<int> dis(0, 1);
  return dis(gen);
}

int UniformRandom(int lower_bound, int upper_bound) {
  
  // All values in [lower_bound, upper_bound] should be equally likely.
  const int INT_COUNT = upper_bound - lower_bound + 1;

  int temp = INT_COUNT;
  std::string binary_str = "";

  while(true)
  {
    binary_str.push_back(char(ZeroOneRandom() + 48));
    temp = temp >> 1;

    if (temp == 0)
    {
      int x = std::stoi(binary_str, 0, 2);

      if (x >= INT_COUNT) {
        temp = INT_COUNT;
        binary_str = "";
      }
      else
      {
        return (x + lower_bound);
      }     
    }
  }
}
bool UniformRandomRunner(TimedExecutor& executor, int lower_bound,
                         int upper_bound) {
  using namespace test_framework;
  vector<int> result;
  executor.Run([&] {
    std::generate_n(back_inserter(result), 100000,
                    std::bind(UniformRandom, lower_bound, upper_bound));
  });

  vector<int> sequence;
  std::transform(begin(result), end(result), back_inserter(sequence),
                 [lower_bound](int result) { return result - lower_bound; });
  return CheckSequenceIsUniformlyRandom(result, upper_bound - lower_bound + 1,
                                        0.01);
}

void UniformRandomWrapper(TimedExecutor& executor, int lower_bound,
                          int upper_bound) {
  RunFuncWithRetries(
      bind(UniformRandomRunner, std::ref(executor), lower_bound, upper_bound));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "lower_bound",
                                       "upper_bound"};
  return GenericTestMain(args, "uniform_random_number.cc",
                         "uniform_random_number.tsv", &UniformRandomWrapper,
                         DefaultComparator{}, param_names);
}
