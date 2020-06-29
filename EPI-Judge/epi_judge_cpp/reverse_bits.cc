#include "test_framework/generic_test.h"

unsigned long long SwapBits(unsigned long long x, int i, int j) {
  
  if (((x >> i) & 1) ^ ((x >> j) & 1))
  {
    x ^= (1 << i);
    x ^= (1 << j);
  }

  return x;

}

unsigned long long ReverseBits(unsigned long long x) {

  unsigned long long int precomputed_reverse[65536];
  unsigned long long int temp;

  for (int i = 0; i < 65536; i++)
  {

    temp = i;

    for (int j = 0; j < 8; j++)
      temp = SwapBits (temp, j, 15 - j);
    
    precomputed_reverse[i] = temp;

  }

  int mask_length = 16;
  int mask = 0xFFFF;

  return (precomputed_reverse[(x & mask)] << (mask_length * 3)) ^ 
      (precomputed_reverse[((x >> mask_length) & mask)] << (mask_length * 2)) ^
      (precomputed_reverse[((x >> (mask_length * 2)) & mask)] << (mask_length)) ^
      (precomputed_reverse[((x >> (mask_length * 3)) & mask)]);

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
