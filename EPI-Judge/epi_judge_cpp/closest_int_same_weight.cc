#include "test_framework/generic_test.h"
#include <iostream>
#include <math.h>

using namespace std;

unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  
  // O(1) time and space solution

  unsigned long long lowest_reset = 0;
  unsigned long long lowest_set = 0;

  // Get lowest reset bit
  lowest_reset = (x ^ (x + 1)) + 1;
  lowest_reset = (lowest_reset >> 1) + (lowest_reset >> 2);
  
  // Get lowest set bit
  lowest_set = x & (~(x - 1));
  lowest_set = lowest_set + (lowest_set >> 1);

  // cout << endl << "lowest reset: " << lowest_reset << endl << "set: " << lowest_set << endl;
  // Take whichever is non-zero
  if(lowest_reset != 1)
  {
    x ^= lowest_reset;
  }
  else
  {
    x ^= lowest_set;
  }
  
  return x;

  /**
  unsigned long long l = x;
  unsigned long long lowest_reset = 0ll;
  unsigned long long lowest_set = 0ll;
  unsigned long long possb_result1 = 0ll;
  unsigned long long possb_result2 = 0ll;

  // Get lowest reset bit
  cout << (x & 1ll);
  if (x & 1ull == 0ull)
  {
    cout << "YES";
    lowest_reset = 0ll;
  }
    
  else
  {
    lowest_reset = (l ^ (l + 1)) + 1;
    lowest_reset = lowest_reset >> 1;
  }
  
  // Get lowest set bit
  lowest_set = x & (~(x - 1));

  if (lowest_reset == 0ll)
  {
    cout << "Yes";
    possb_result1 = x >> 1;
    lowest_set = lowest_set + (lowest_set >> 1);
    possb_result2 = x ^ lowest_set;
  }
  else
  {
    possb_result1 = x - lowest_reset;  // remove the lowest reset
    lowest_reset = lowest_reset + (lowest_reset >> 1);
    possb_result2 = x ^ lowest_reset;  // swap lowest reset with adjacent set
  }

  cout << "\npossb result 2: " << possb_result2;
  cout << "\npossb result 1: " << possb_result1 << "\n";

  unsigned long long c1, c2;
  if (possb_result2 > x)
    c1 = possb_result2 - x;
  else
  {
    c1 = x - possb_result2;
  }

  if (possb_result1 > x)
    c2 = possb_result1 - x;
  else
  {
    c2 = x - possb_result1;
  }
  
  if (c1 < c2)
    return possb_result2;
  else
  {
    return possb_result1;
  }
  
  */
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
