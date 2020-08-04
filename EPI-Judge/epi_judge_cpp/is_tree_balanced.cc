#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

int check_ht (const unique_ptr<BinaryTreeNode<int>>& curr_node) {

  if (!curr_node) return 0;

  int left = check_ht (curr_node -> left);
  int right = check_ht (curr_node -> right);

  if (left == -1 || right == -1)  return -1;

  if (abs (left - right) > 1) return -1;

  return 1 + std::max (left, right);

}
bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {

  int ht = check_ht (tree);

  return ht != -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
