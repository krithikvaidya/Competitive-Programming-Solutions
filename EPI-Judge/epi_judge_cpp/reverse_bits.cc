#include "test_framework/generic_test.h"

unsigned long long SwapBits(unsigned long long x, int i, int j) {
  
  if (((x >> i) & 1) != ((x >> j) & 1))
  {
    long long y = (1ll << i) | (1ll << j);  
    x = x ^ y;
  }
  return x;
}

unsigned long long ReverseBits(unsigned long long x) {

  unsigned long long precomputed_reverse[65536];
  for (unsigned long long i = 0ll; i < 65536; i++)
  {
    unsigned long long temp = i;
    for(int j = 0; j < 8; j++)
    {
      int k = 15 - j;
      temp = SwapBits(temp, j, k);
    }

    precomputed_reverse[i] = temp;
  }

  const int kMaskSize = 16;
  const int kBitMask = 0xFFFF;
  return precomputed_reverse[x & kBitMask] << (3 * kMaskSize) |
         precomputed_reverse[(x >> kMaskSize) & kBitMask] << (2 * kMaskSize) |
         precomputed_reverse[(x >> (2 * kMaskSize)) & kBitMask] << kMaskSize |
         precomputed_reverse[(x >> (3 * kMaskSize)) & kBitMask];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
