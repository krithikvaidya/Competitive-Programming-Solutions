#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    deque<int> subarr;
    int curr_max = 0;

    for(int i = 1; i < k; i++)
    {
        if(arr[i] > arr[curr_max])
            curr_max = i;
    }

    cout<<arr[curr_max]<<" ";

    for(int i = 1; i <= n - k; i++)
    {
        if(curr_max == i - 1)
        {
            curr_max = i;
            for(int j = i + 1; j <= i+k-1; j++)
                if(arr[j] > arr[curr_max])
                    curr_max = j;
        }
        else if(arr[i+k-1] > arr[curr_max])
            curr_max = i+k-1;

        cout<<arr[curr_max]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}


