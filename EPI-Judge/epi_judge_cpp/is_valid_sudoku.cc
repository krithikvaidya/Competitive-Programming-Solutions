#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
using namespace std;

bool HasDuplicates (const vector<vector<int>>& partial_assignment, int start_row, int end_row, int start_col, int end_col)
{
  deque<bool> is_present (10, false);

  for (int i = start_row; i <= end_row; i++)
  {
    for (int j = start_col; j <= end_col; j++)
    {

      if (partial_assignment[i][j] == 0)
        continue;

      if (is_present[partial_assignment[i][j]])
        return true;
      is_present[partial_assignment[i][j]] = true;
    }
  }

  return false;

}

// Check if a partially filled matrix has any conflicts.
bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {

  // row check
  for (int i = 0; i < 9; i++)
  {
    if (HasDuplicates (partial_assignment, i, i, 0, 8))
      return false;
  }

  // column check
  for (int i = 0; i < 9; i++)
  {
    if (HasDuplicates (partial_assignment, 0, 8, i, i))
      return false;
  }

  // subgrid check

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (HasDuplicates (partial_assignment, i * 3, i * 3 + 2, j * 3, j * 3 + 2))
        return false;
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"partial_assignment"};
  return GenericTestMain(args, "is_valid_sudoku.cc", "is_valid_sudoku.tsv",
                         &IsValidSudoku, DefaultComparator{}, param_names);
}
