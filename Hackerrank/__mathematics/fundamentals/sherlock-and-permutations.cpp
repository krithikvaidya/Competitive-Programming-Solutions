#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long int calc_fact(long long int n, long long int c) {
  long long int res = 1ll;
  for (long long int i = 2ll; i <= n; i++)
    res = (res * i) % c;

  return res;
}

long long int modularexp(long long int a, long long int b, long long int c) {
  long long int result = 1ll;

  while (b > 0) 
  {
    if (b & 1)
      result = result * a % c;

    a = a * a % c;
    b >>= 1;
  }

  return result;
}

// Complete the solve function below.
long long int solve(long long int n, long long int m) 
{
  long long int temp1 = calc_fact(m - 1 + n, 1000000007ll);
  long long int temp2 =
      calc_fact(m - 1, 1000000007ll) * calc_fact(n, 1000000007ll);
    temp2 %= 1000000007ll;

  temp2 = modularexp(temp2, 1000000005ll, 1000000007ll) % 1000000007ll;

  return (temp1 * temp2) % 1000000007ll;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        int result = solve(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

