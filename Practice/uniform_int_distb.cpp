#include <iostream>
#include <random>

// Generate 10000 instances of random numbers
// between 0 and 9.
#define UPPER_BOUND 9
#define LOWER_BOUND 0
#define EXPERIMENT_COUNT 10000

using namespace std;

int main()
{
    // default_random_generator is the 
    // source of randomness. Can seed
    // for pseudorandomness.
    default_random_engine generator;

    // Initialize of uniform_int_distribution class
    uniform_int_distribution<int> distribution(LOWER_BOUND, UPPER_BOUND);

    int n = UPPER_BOUND - LOWER_BOUND + 1;
    int instances[n] = { 0 };

    for (int i = 0; i < EXPERIMENT_COUNT; i++)
    {
        int random_number = distribution(generator);
        instances[random_number]++;
    }

    cout << "Expected probability: "
         << float(1) / float(n) << endl; 
  
    cout << "uniform_int_distribution ("
         << LOWER_BOUND << ", " << UPPER_BOUND << ")" << endl;

    // Displaying the probability of each number 
    // after generating values 10000 times. 
    for (int i = 0; i < n; i++) 
        cout << LOWER_BOUND + i << ": "
             << (float)instances[i] / (float)(EXPERIMENT_COUNT) 
             << endl; 
  
    return 0; 
}