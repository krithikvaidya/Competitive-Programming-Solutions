#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Interval {
  int left, right;
};

bool sort_interval (const Interval& in1, const Interval& in2) {
  return in1.left < in2.left;
}

int FindMinimumVisits(vector<Interval> intervals) {
  
  sort (intervals.begin(), intervals.end(), sort_interval);

  int vc = 1;
  int max_val = intervals[0].right;

  for (int i = 1; i < intervals.size(); i++) {

    if (intervals[i].left <= max_val) continue;

    vc++;
    max_val = intervals[i].right;

  }

  return vc;
}
namespace test_framework {
template <>
struct SerializationTrait<Interval> : UserSerTrait<Interval, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"intervals"};
  return GenericTestMain(args, "minimum_points_covering_intervals.cc",
                         "minimum_points_covering_intervals.tsv",
                         &FindMinimumVisits, DefaultComparator{}, param_names);
}
