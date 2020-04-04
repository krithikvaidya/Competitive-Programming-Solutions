#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
bool CanReachEnd(const vector<int>& max_advance_steps) {


  int end_index = max_advance_steps.size() - 1;
  int curr_index = 0;
  int max_possb_next_index = 0;

  while (curr_index <= max_possb_next_index && max_possb_next_index < end_index)
  {

    if (curr_index + max_advance_steps[curr_index] > max_possb_next_index)
      max_possb_next_index = curr_index + max_advance_steps[curr_index];

    curr_index++;
  }

  return max_possb_next_index >= end_index ? true : false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
