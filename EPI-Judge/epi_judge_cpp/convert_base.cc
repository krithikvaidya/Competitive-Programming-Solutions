#include <string>

#include "test_framework/generic_test.h"
using std::string;

string ConvertBase(const string& num_as_string, int b1, int b2) {
  
  if (num_as_string == "0")
    return "0";

  int base_10_val = 0;
  int pwr = 0;

  for (int i = num_as_string.size() - 1; i > 0; i--)
  {
    if (isdigit(num_as_string[i]))
      base_10_val += (num_as_string[i] - '0') * pow (b1, pwr);
    else
      base_10_val += (num_as_string[i] - 'A' + 10) * pow (b1, pwr);
    pwr++;

  }

  if (num_as_string[0] != '-')
  {
    if (isdigit(num_as_string[0]))
      base_10_val += (num_as_string[0] - '0') * pow (b1, pwr);
    else
      base_10_val += (num_as_string[0] - 'A' + 10) * pow (b1, pwr);
  }

  string base_x_val = "";
  // std::cout << "\n\n" << base_10_val << "\n\n";

  while (base_10_val)
  {
    int rem = base_10_val % b2;
    base_10_val /= b2;

    if (rem >= 10)
    {
      base_x_val.push_back('A' + rem - 10);
    }
    else
    {
      base_x_val.push_back('0' + rem);
    }
    
  }

  if (num_as_string[0] == '-')
    base_x_val.push_back('-');

  return {base_x_val.rbegin(), base_x_val.rend()};

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num_as_string", "b1", "b2"};
  return GenericTestMain(args, "convert_base.cc", "convert_base.tsv",
                         &ConvertBase, DefaultComparator{}, param_names);
}
