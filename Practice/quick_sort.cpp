#include <bits/stdc++.h>

using namespace std;


int partition (vector<int>& vec, int p, int r) {

	int less_index = p;
	int curr_index = p;

	while (curr_index <= r) {
		if (vec[curr_index] <= vec[r]) {
			swap (vec[curr_index], vec[less_index]);
			less_index++;
		}
		curr_index++;
	}

	return less_index - 1;

}

void randomize_pivot (vector<int>& vec, int p, int r) {

	srand (time (NULL));
	int pivot = p + rand() % (r - p);

	swap (vec[pivot], vec[r]);

}

void quick_sort (vector<int>& vec, int p, int r) {

	if (p < r) {

		randomize_pivot (vec, p, r);
		int x = partition (vec, p, r);

		quick_sort (vec, p, x - 1);
		quick_sort (vec, x + 1, r);

	}
	
}

int main() {

	vector <int> vec = { 15, 4, 0, -12, 2, 1};

	quick_sort (vec, 0, vec.size() - 1);

	for (int a: vec) cout << a << " ";
	

} 