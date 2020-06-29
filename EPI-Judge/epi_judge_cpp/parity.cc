#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  
  // short parity[65536];
  // for (unsigned long long i = 0ll; i < 65536; i++)
  // {
  //   unsigned long long temp = i;
  //   short cparity = 0;

  //   while(temp) {
  //     temp = temp ^ (temp & ~(temp - 1));
  //     cparity ^= 1;
  //   }

  //   parity[i] = cparity;
  // }

  // unsigned long long bitmask = 0xFFFFull;

  // return parity[(x >> 48) & bitmask] ^ parity[(x >> 32) & bitmask] ^ parity[(x >> 16) & bitmask] ^ parity[x & bitmask];
  x = x ^ (x >> 32);
  x = x ^ (x >> 16);
  x = x ^ (x >> 8);
  x = x ^ (x >> 4);
  x = x ^ (x >> 2);
  x = x ^ (x >> 1);

  return x & 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
