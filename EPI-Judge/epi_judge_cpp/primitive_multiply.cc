// TODO: fix

#include "test_framework/generic_test.h"

unsigned long long Add(unsigned long long result, unsigned long long y)
{

  short carry_bit = 0, temp1, temp2;
  unsigned long long sum = 0ull;
  unsigned long long bitmask = 1ull;

  while (bitmask)
  {
    temp1 = result & bitmask;
    temp2 = y & bitmask;

    sum |= (temp1 ^ temp2 ^ carry_bit);

    if((temp1 & temp2) | (temp2 & carry_bit) | (carry_bit & temp1))
      carry_bit <<= 1;
    else
    {
      carry_bit = 0;
    }
    
    bitmask <<= 1;
  }

  return sum | carry_bit;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  
  unsigned long long result = 0ull;

  while (x)
  {

    if (x & 1)
    {
      result = Add(result, y);
    }
    
    x >>= 1;
    y <<= 1;
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
