#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for(int y = 0; y < t; y++) {
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<int, pair<int, int>> org_oddeven_occs;
        for(int i = 0; i < n; i++) {
            if(i & 1)
                org_oddeven_occs[a[i]].first++;
            else
                org_oddeven_occs[a[i]].second++;
        }

        sort(a.begin(), a.end());
        map<int, pair<int, int>> sorted_oddeven_occs;
        for(int i = 0; i < n; i++) {
            if(i & 1)
                sorted_oddeven_occs[a[i]].first++;
            else
                sorted_oddeven_occs[a[i]].second++;
        }

        bool flag = true;
        for(auto kv: org_oddeven_occs) {
            if(kv.second != sorted_oddeven_occs[kv.first]) {
                cout << "NO\n";
                flag = false;
                break;
            }
        }

        if(flag) cout << "YES\n";
    }

}

