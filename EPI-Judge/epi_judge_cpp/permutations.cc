#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<vector<int>> perms;

void compute_perms (vector<int> A, vector<int> curr_perm, int index) {

  if (index == A.size())
  {
    perms.emplace_back (curr_perm);
    return;
  }

  for (int i = index; i < A.size(); i++) {

    std::swap (A[i], A[index]);
    curr_perm.push_back (A[index]);

    compute_perms (A, curr_perm, index + 1);

    curr_perm.pop_back();
    std::swap (A[i], A[index]);

  }

}

vector<vector<int>> Permutations(vector<int> A) {
  
  perms = {};

  compute_perms (A, {}, 0);

  return perms;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "permutations.cc", "permutations.tsv",
                         &Permutations, UnorderedComparator{}, param_names);
}
