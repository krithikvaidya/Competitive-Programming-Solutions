#include "test_framework/generic_test.h"
#include <math.h>

using namespace std;


bool IsPalindromeNumber(int x) {
  
  // Check if given int is palindromic
  if (x < 0)
    return false;

  bool flag = true;

  const int num_digits = static_cast<int>(floor(log10(x))) + 1;
  int remove_MSD_mask = static_cast<int>(pow(10, num_digits - 1));

  for (int i = 0; i < (num_digits)/2; i++) {
    
    if ((x / remove_MSD_mask) != (x % 10))
    {
      flag = false;
      break;
    }
    
    x %= remove_MSD_mask;
    x /= 10;
    remove_MSD_mask /= 100;
  }

  // cout <<"\n" << x << "\n";

  return flag;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
