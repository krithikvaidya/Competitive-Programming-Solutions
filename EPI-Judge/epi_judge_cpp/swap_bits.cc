#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
  
  if (((x >> i) & 1) != ((x >> j) & 1))
  {
    long long y = (1ll << i) | (1ll << j);  
    x = x ^ y;
  }
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
