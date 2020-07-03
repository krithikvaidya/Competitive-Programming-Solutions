#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  
  if (start == finish)
    return L;

  auto prev = L;
  auto curr = L;
  auto next = L -> next;

  int i = 1;
  shared_ptr<ListNode<int>> temp2 = nullptr;

  while (i < start)
  {
    if (i == start - 1)
      temp2 = curr;

    curr = prev = next;
    next = next -> next;
    
    i++;
  }

  auto temp1 = curr;

  while (i < finish)
  {

    curr = next;
    next = next -> next;
    curr -> next = prev;
    prev = curr;
    i++;
  }

  temp1 -> next = next;
  if (start != 1)
    temp2 -> next = curr; 

  if (start != 1)
    return L;
  else
  {
    return curr;
  }
  
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
