#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;

void ReverseWords(string* s) {
  
  string reversed = "";
  string curr_word = "";

  for (int i = s -> size() - 1; i >= 0; i--)
  {
    if (*(s + i) == ' ')
    {
      reversed += {curr_word.rbegin(), curr_word.rend()};
      reversed += " ";
      curr_word = "";
    }
    else
    {
      curr_word += s1[i];
    }
    
  }

  reversed += {curr_word.rbegin(), curr_word.rend()};

  std::cout << "\n\n" << reversed << "\n\n";
  *s = reversed;

  return;
}
string ReverseWordsWrapper(TimedExecutor& executor, string s) {
  string s_copy = s;

  executor.Run([&] { ReverseWords(&s_copy); });

  return s_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "s"};
  return GenericTestMain(args, "reverse_words.cc", "reverse_words.tsv",
                         &ReverseWordsWrapper, DefaultComparator{},
                         param_names);
}
