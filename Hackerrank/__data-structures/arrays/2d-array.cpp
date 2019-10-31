#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max_sum = INT_MIN, currsum = 0;
    int itop = 0, jtop = 0, imid = 1, jmid = 1, ibot = 2, jbot = 0;

    while(itop + 2 < 6)
    {
        cout<<itop<<" "<<jtop<<endl;
        cout<<imid<<" "<<jmid<<endl;
        cout<<ibot<<" "<<jbot<<endl;
        while(jtop + 2 < 6)
        {
            
            currsum = arr[itop][jtop] + arr[itop][jtop + 1] + arr[itop][jtop + 2];
            currsum += arr[imid][jmid];
            currsum += arr[ibot][jbot] + arr[ibot][jbot + 1] + arr[ibot][jbot + 2];
            // cout<<currsum<<endl;
            if(currsum > max_sum)
                max_sum = currsum;
            jtop++;
            jbot++;
            jmid++;
        }
        itop++;
        imid++;
        ibot++;
        jtop = 0;
        jmid = 1;
        jbot = 0;
    }
    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

