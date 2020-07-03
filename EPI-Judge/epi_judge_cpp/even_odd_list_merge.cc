#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {
  
  if (!L)
    return nullptr;
  
  auto even = L;
  auto odd = L -> next;
  auto first_odd = odd;

  while (even && odd)
  {
    even -> next = odd -> next;
    if (odd -> next)
      odd -> next = odd -> next -> next;

    if (even -> next)
      even = even -> next;
    odd = odd -> next;
  }

  even -> next = first_odd;

  return L;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "even_odd_list_merge.cc",
                         "even_odd_list_merge.tsv", &EvenOddMerge,
                         DefaultComparator{}, param_names);
}
