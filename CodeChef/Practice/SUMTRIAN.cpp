#include <bits/stdc++.h>
using namespace std;
long long calc_sum(int row, int col, vector<int> triangle[], vector<long long> max_sum[])
{
    if(col < 0 || row < 0)
        return 0;
    if(col <= row - 1)
    {
        if(max_sum[row][col] == 0)
        {
            max_sum[row][col] = max(calc_sum(row - 1, col, triangle, max_sum), calc_sum(row - 1, col - 1, triangle, max_sum)) + triangle[row][col];
            return max_sum[row][col];
        }
        else
            return max_sum[row][col];
    }
    else
    {
        if(max_sum[row][col] == 0)
        {
            max_sum[row][col] = calc_sum(row - 1, col - 1, triangle, max_sum) + triangle[row][col];
            return max_sum[row][col];
        }
        else
            return max_sum[row][col];
    }
}
int main()
{
    int n, temp, rows;
    long long max, sum;
    cin>>n;
    vector<long long> answers;
    for(int i = 0; i < n; i++)
    {
        cin>>rows;
        vector<int> triangle[rows];
        vector<long long> max_sum[rows];
        for(int j = 0; j < rows; j++)
        {
            for(int k = 0; k <= j; k++)
            {
                cin>>temp;
                triangle[j].push_back(temp);
                max_sum[j].push_back(0ll);
            }
        }
        max = 0ll;
        for(int j = 0; j < rows; j++)
        {
            sum = calc_sum(rows - 1, j, triangle, max_sum);
            max = sum > max ? sum : max;
        }
        answers.push_back(max);
    }
    for(int i = 0; i < n; i++)
        cout<<answers[i]<<"\n";
}
