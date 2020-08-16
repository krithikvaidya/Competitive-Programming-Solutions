#include <memory>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;
using std::stack;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  
  stack<BinaryTreeNode<int>*> to_process;
  vector<int> inorder;

  auto curr = tree.get();

  while (!to_process.empty() || curr) {

    if (curr)
    {
      to_process.push (curr);
      curr = curr -> left.get();
      continue;
    }

    curr = to_process.top();
    to_process.pop();
    
    inorder.push_back (curr -> data);

    curr = curr -> right.get();

  }

  return inorder;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_inorder.cc", "tree_inorder.tsv",
                         &InorderTraversal, DefaultComparator{}, param_names);
}
