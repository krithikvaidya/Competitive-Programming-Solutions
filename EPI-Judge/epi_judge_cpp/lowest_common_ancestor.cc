#include <memory>

#include "binary_tree_node.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::unique_ptr;

struct LCA_present {

  int status;
  BinaryTreeNode<int>* node;

};

LCA_present get_LCA (const unique_ptr<BinaryTreeNode<int>>& curr,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {

  if (!curr)  return {0, nullptr};

  int status = 0;

  LCA_present left = get_LCA (curr -> left, node0, node1);
  LCA_present right = get_LCA (curr -> right, node0, node1);

  if (left.status == 2) return left;
  if (right.status == 2) return right;

  status += left.status + right.status + (curr == node0) + (curr == node1);
  // std::cout << "\ncurr: " << curr -> data << " status: " << status << "\n";

  return {status, curr.get()};
}


BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  
  auto r = (get_LCA (tree, node0, node1)).node;
  std::cout << tree.get() -> data;
  return r;

}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(tree, node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
