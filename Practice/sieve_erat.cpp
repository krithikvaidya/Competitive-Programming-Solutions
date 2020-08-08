#include <bits/stdc++.h>

using namespace std;

void sieve (vector<bool>& prime) {

	int MAX = prime.size();
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i < MAX; i++) {

		if (prime[i]) {

			for (int j = i * i; j < MAX; j += i) // why start at i * i? Because all multiples of i
                                                 // upto i - 1 have already been covered earlier.
			{
				prime[j] = false;
			}

		}

	}

	// Additional optimization - can only use odd numbers in the sieve, cuts
    // space usage by half.

}

int main() {

	// prime is initialized to all true, i.e. all are assumed to be prime.
	vector<bool> prime (100, true);

	sieve (prime);

	for (int i = 0; i < 100; i++) 
		cout << i << " " << prime[i] << "\n";
}