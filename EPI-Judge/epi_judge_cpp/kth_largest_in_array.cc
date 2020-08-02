#include <vector>
#include <time.h>

#include "test_framework/generic_test.h"
using std::vector;


int partition_around_pivot (vector<int>& arr, int low, int high) {

  srand (time(NULL));

  if (high == low)
    return low;

  int random_pivot_index = low + rand() % (high - low);
  // std::cout << random_pivot_index << "\n";
  int new_pivot_index = low;

  std::swap (arr[high], arr[random_pivot_index]);

  for (int i = low; i <= high; i++) {

    if (arr[i] >= arr[high]) {

      std::swap (arr[i], arr[new_pivot_index++]);

    }

  }

  return new_pivot_index - 1;

}

// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int FindKthLargest(int k, vector<int>* A_ptr) {

  vector<int>& arr = *A_ptr;
  int low = 0, high = arr.size() - 1;

  while (low <= high) {

    int new_pivot_index = partition_around_pivot (arr, low, high);

    if (new_pivot_index == k - 1) return arr[k - 1];

    else if (new_pivot_index > k - 1) {
      high = new_pivot_index - 1;
    }

    else low = new_pivot_index + 1;

  }
  
  return 0;
}
int FindKthLargestWrapper(int k, vector<int>& A) {
  return FindKthLargest(k, &A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "A"};
  return GenericTestMain(args, "kth_largest_in_array.cc",
                         "kth_largest_in_array.tsv", &FindKthLargestWrapper,
                         DefaultComparator{}, param_names);
}
