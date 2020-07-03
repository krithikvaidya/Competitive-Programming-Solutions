#include <string>

#include "test_framework/generic_test.h"
using std::string;
using namespace std;


string LookAndSay(int n) {
  
  string old_num = "1";
  string new_num = "";
  int curr_len = 1;

  for (int i = 1; i < n; i++)
  {

    curr_len = 1;

    for (int j = 1; j < old_num.size(); j++)
    {
      if (old_num[j] != old_num[j - 1])
      {
        new_num = new_num + to_string(curr_len) + old_num[j - 1];
        curr_len = 0;
      }

      curr_len++;
    }

    new_num = new_num + to_string(curr_len) + old_num[old_num.size() - 1];
    old_num = new_num;
    new_num = "";

  }

  return old_num;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "look_and_say.cc", "look_and_say.tsv",
                         &LookAndSay, DefaultComparator{}, param_names);
}
