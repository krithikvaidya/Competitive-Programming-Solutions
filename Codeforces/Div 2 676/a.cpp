#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int j = 0; j < t; j++) {

        int a, b;
        cin >> a >> b;

        long int res = 0l;
        long int i = 0l;
        while ((a != 0) && (b != 0)) {

            if ((a & 1) != (b & 1))
                res += (pow (2l, i));

            a >>= 1;
            b >>= 1;

            i++;

        }

        while (a != 0) {
            if (a & 1)
                res += (pow (2l, i));
            i++;
            a>>=1;
        }

        while (b != 0) {
            if (b & 1)
                res += (pow (2l, i));
            i++;
            b>>=1;
        }


        cout << res << "\n";

    }
    

}