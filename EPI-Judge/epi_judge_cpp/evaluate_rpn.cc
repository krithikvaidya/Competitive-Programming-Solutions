#include <string>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

vector<string> tokenize(const string& s, char c) {

    auto end = s.cend();
    auto start = end;

    vector<string> v;
    for( auto it = s.cbegin(); it != end; ++it ) {
        if( *it != c ) {
            if( start == end )
                start = it;
            continue;
        }
        if( start != end ) {
            v.emplace_back(start, it);
            start = end;
        }
    }
    if( start != end )
        v.emplace_back(start, end);
    return v;
}

int Evaluate(const string& expression) {
  
  vector<string> tokenized_expr = tokenize(expression, ',');

  int neg = 1;
  int i = 0;

  if (tokenized_expr[0] == "-")
  {
    neg = -1;
    i++;
  }

  std::stack<int> rpn_stack;
  int val1, val2;

  while (i < tokenized_expr.size())
  {

    if (tokenized_expr[i] == "+")
    {
      val2 = rpn_stack.top();
      rpn_stack.pop();
      val1 = rpn_stack.top();
      rpn_stack.pop();

      rpn_stack.emplace (val1 + val2);
    }
    else if (tokenized_expr[i] == "-")
    {
      val2 = rpn_stack.top();
      rpn_stack.pop();
      val1 = rpn_stack.top();
      rpn_stack.pop();

      rpn_stack.emplace (val1 - val2);
    }
    else if (tokenized_expr[i] == "*")
    { 

      val2 = rpn_stack.top();
      rpn_stack.pop();
      val1 = rpn_stack.top();
      rpn_stack.pop();

      rpn_stack.emplace (val1 * val2);

    }
    else if (tokenized_expr[i] == "/")
    {
      val2 = rpn_stack.top();
      rpn_stack.pop();
      val1 = rpn_stack.top();
      rpn_stack.pop();

      rpn_stack.emplace (val1 / val2);
    }
    else
    {
      rpn_stack.emplace (stoi(tokenized_expr[i]));
    }
    
    i++;
  }

  return neg * rpn_stack.top();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"expression"};
  return GenericTestMain(args, "evaluate_rpn.cc", "evaluate_rpn.tsv", &Evaluate,
                         DefaultComparator{}, param_names);
}
