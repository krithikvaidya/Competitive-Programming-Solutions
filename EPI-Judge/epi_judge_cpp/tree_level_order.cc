#include <memory>
#include <vector>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;
using std::queue;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  
  vector<vector<int>> nodes;
  queue <BinaryTreeNode<int>* > current_level_nodes;

  current_level_nodes.emplace (tree.get());

  while (!current_level_nodes.empty())
  {
    queue <BinaryTreeNode<int>* > next_level_nodes;
    vector<int> current_level;

    while (!current_level_nodes.empty())
    {
      BinaryTreeNode<int>* node = current_level_nodes.front();
      current_level_nodes.pop();

      if (node)
      {
        current_level.emplace_back (node -> data);
        next_level_nodes.emplace ((node -> left).get());
        next_level_nodes.emplace ((node -> right).get());
      }

    }

    if (!current_level.empty())
    {
      nodes.emplace_back (current_level);
    }

    current_level_nodes = next_level_nodes;

  }

  return nodes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}
