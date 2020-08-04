#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

int getdepth (BinaryTreeNode<int>* node) {

  int depth = 0;
  while (node) {
    // std::cout << node -> data << "\n" << " hmm\n";
    node = node -> parent;
    depth++;
  }

  return depth;

}

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  
  BinaryTreeNode<int>* n0 = node0.get();
  BinaryTreeNode<int>* n1 = node1.get();

  int depth0 = getdepth (n0);
  int depth1 = getdepth (n1);
  
  // std::cout << "\nd0: " << depth0 << " d1: " <<depth1<<"\n";
  if (depth0 > depth1) {
    std::swap (depth0, depth1);
    std::swap (n0, n1);
  }

  while (depth1 != depth0) {
    n1 = n1 -> parent;
    depth1--;
  }

  while (n1 != n0) {
    n1 = n1 -> parent;
    n0 = n0 -> parent;
  }

  return n1;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
