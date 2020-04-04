#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> Multiply(vector<int> num1, vector<int> num2) {
  
  int sign = (num1[0] < 0) ^ (num2[0] < 0) ? -1 : 1;

  num1[0] = abs(num1[0]);
  num2[0] = abs(num2[0]);
  
  if((num1.size() == 1 || num2.size() == 1) && (num1[0] == 0 || num2[0] == 0))
    return { 0 };

  int size1 = num1.size();
  int size2 = num2.size();

  vector<int> result(size1 + size2, 0);
  int carry, offset = 0;

  for (int i = size1 - 1; i >= 0; i--)
  {
    carry = 0;
    for (int j = size2 - 1; j >= 0; j--)
    {
      result[i + j + 1] += num1[i] * num2[j];
      result[i + j] += (result[i + j + 1] / 10);
      result[i + j + 1]  %= 10;
    }
    offset++;
  }

  int i;
  for (i = 0; result[i] == 0; i++);

  vector<int> final_result(result.begin() + i, result.end());

  final_result[0] *= sign;
  return final_result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
