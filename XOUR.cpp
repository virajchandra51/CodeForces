#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        map<long long, vector<long long> > mp; // config - push all numbers
        for (auto it : a)
        {
            long long config = 0;
            long long copy = it;
            long long in = 0;
            while (copy > 0)
            {
                if (in >= 2 && copy & 1 == 1)
                    config += (1 << in);
                copy >>= 1;
                in++;
            }
            mp[config].push_back(it);
        } // O(nlogn)
        for (auto &it : mp)
        {
            sort(it.second.begin(), it.second.end());
        } // O(nlogn)
        unordered_map<long long, long long> ind;
        for (auto it : mp) // O(n)
            ind[it.first] = 0;
        for (auto &it : a) // O(n)
        {
            long long config = 0;
            long long copy = it;
            long long in = 0;
            while (copy > 0)
            {
                if (in >= 2 && copy & 1 == 1)
                    config += (1 << in);
                copy >>= 1;
                in++;
            }
            it = mp[config][ind[config]];
            ind[config]++;
        }
        for (auto it : a)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// tc - O(nlogn)
// sc - O(n)