#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::shared_ptr;

int calc_len (shared_ptr<ListNode<int>> l)
{
  int len = 0;

  while (l)
  {
    len++;
    l = l -> next;
  }

  return len;
}

void advanceByK (int k, shared_ptr<ListNode<int>>* l)
{
  while (k--)
    *l = (*l) -> next;
}

shared_ptr<ListNode<int>> OverlappingNoCycleLists(
    shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {
  
  if (!l0 || !l1)
    return nullptr;

  int len0 = calc_len (l0);
  int len1 = calc_len (l1);

  advanceByK (abs (len0 - len1), len0 > len1 ? &l0 : &l1);
  
  while (l0 && l1)
  {
    if (l0 == l1)
      return l0;
    
    l0 = l0 -> next;
    l1 = l1 -> next;
  }

  return nullptr;

}
void OverlappingNoCycleListsWrapper(TimedExecutor& executor,
                                    shared_ptr<ListNode<int>> l0,
                                    shared_ptr<ListNode<int>> l1,
                                    shared_ptr<ListNode<int>> common) {
  if (common) {
    if (l0) {
      auto i = l0;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l0 = common;
    }

    if (l1) {
      auto i = l1;
      while (i->next) {
        i = i->next;
      }
      i->next = common;
    } else {
      l1 = common;
    }
  }

  auto result = executor.Run([&] { return OverlappingNoCycleLists(l0, l1); });

  if (result != common) {
    throw TestFailure("Invalid result");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "l0", "l1", "common"};
  return GenericTestMain(
      args, "do_terminated_lists_overlap.cc", "do_terminated_lists_overlap.tsv",
      &OverlappingNoCycleListsWrapper, DefaultComparator{}, param_names);
}
