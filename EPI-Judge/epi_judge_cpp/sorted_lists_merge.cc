#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  
  shared_ptr<ListNode<int>> L1_head(new ListNode<int>);
  L1_head -> next = L1;
  L1 = L1_head;
  
  while (L1 -> next && L2)
  {
    if (L1 -> next -> data <= L2 -> data)
      L1 = L1 -> next;

    else
    {
      auto temp2 = L1 -> next;
      L1 -> next = L2;
      auto temp3 = L2 -> next;
      L2 -> next = temp2;
      L2 = temp3;
      L1 = L1 -> next;
    }
    
  }

  if (L2)
    L1 -> next = L2;

  return L1_head -> next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
