#include <bits/stdc++.h>

#define lli long long int
#define ld long double

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n  >> m;
    cin.ignore();

    string chef, country;

    map<string, string> chef_country;
    map<string, int> country_votes;
    map<string, int> chef_votes;

    for (int i = 0; i < n; i++)
    {
        cin >> chef;
        cin >> country;

        chef_country[chef] = country;
    }

    int max_chef = 0, max_country = 0;
    vector<string> corr_chef;
    vector<string> corr_country;

    for (int i = 0; i < m; i++)
    {
        cin >> chef;

        chef_votes[chef]++;

        if (chef_votes[chef] == max_chef)
        {
            // max_chef = chef_votes[chef];
            corr_chef.push_back(chef);
        }

        else if (chef_votes[chef] > max_chef)
        {
            corr_chef.clear();
            max_chef = chef_votes[chef];
            corr_chef.push_back(chef);
        }

        country = chef_country[chef];

        country_votes[country]++;

        if (country_votes[country] == max_country)
        {
            // max_chef = chef_votes[chef];
            corr_country.push_back(country);
        }

        else if (country_votes[country] > max_country)
        {
            corr_country.clear();
            max_country = country_votes[country];
            corr_country.push_back(country);
        }

    }

    sort (corr_country.begin(), corr_country.end());
    sort (corr_chef.begin(), corr_chef.end());

    cout << corr_country[0] << "\n" << corr_chef[0]; 

}

