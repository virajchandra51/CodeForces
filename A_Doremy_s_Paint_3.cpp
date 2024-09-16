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
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // input

        map<long long, long long> frequency_map;
        for (int i = 0; i < n; i++)
            frequency_map[a[i]]++;

        if (frequency_map.size() >= 3)
        {
            cout << "No" << endl;
        }
        else
        {
            long long freq_1 = frequency_map.begin()->second;
            long long freq_2 = frequency_map.rbegin()->second;
            if (abs(freq_1 - freq_2) <= 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}

// tc - O(1)
// sc - O(1)