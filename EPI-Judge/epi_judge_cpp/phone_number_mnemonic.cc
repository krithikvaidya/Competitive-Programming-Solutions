#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;
using namespace std;

vector<string> mapping = {
  "0",
  "1",
  "ABC",
  "DEF",
  "GHI",
  "JKL",
  "MNO",
  "PQRS",
  "TUV",
  "WXYZ"
};

vector<string> mnemonics;

void calc_mnemonic (const string& phone_number, int index, string* partial_mnemonic)
{
  if (index == phone_number.size())
    mnemonics.push_back(*partial_mnemonic);

  else
  {
    for (char ch: mapping[phone_number[index] - '0'])
    {
      (*partial_mnemonic)[index] = ch;
      calc_mnemonic (phone_number, index + 1, partial_mnemonic);
    }
  }
  
}

vector<string> PhoneMnemonic(const string& phone_number) {

  mnemonics.clear();

  const int PhNoLen = 10;

  string partial_mnemonic(phone_number.size(), 0);

  calc_mnemonic (phone_number, 0, &partial_mnemonic);

  return mnemonics;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"phone_number"};
  return GenericTestMain(args, "phone_number_mnemonic.cc",
                         "phone_number_mnemonic.tsv", &PhoneMnemonic,
                         UnorderedComparator{}, param_names);
}
