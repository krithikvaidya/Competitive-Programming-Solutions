#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
using std::string;

vector<vector<int>> pwr_set;

void gen_pwr_set (const vector<int>& input_set, string curr_set, int index) {

  if (index == curr_set.size()) {

    vector<int> set_to_push;

    for (int i = 0; i < curr_set.size(); i++) {
      if (curr_set[i] - '0') 
        set_to_push.emplace_back (input_set[i]);
    }

    pwr_set.emplace_back (set_to_push);

    return;
  }

  gen_pwr_set (input_set, curr_set, index + 1);

  curr_set[index] = '1';

  gen_pwr_set (input_set, curr_set, index + 1);

}


vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  
  pwr_set = {};
  
  std::string bits;

  for (int i = 0; i < input_set.size(); i++) {
    bits.push_back ('0');
  }

  gen_pwr_set (input_set, bits, 0);

  return pwr_set;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input_set"};
  return GenericTestMain(args, "power_set.cc", "power_set.tsv",
                         &GeneratePowerSet, UnorderedComparator{}, param_names);
}
