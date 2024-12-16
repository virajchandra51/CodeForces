#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];

        map<long long, long long> mp;
        for (long long i = 0; i < n; i++) // n
            mp[a[i]]++;

        long long current_highest_freq = 0;
        for (auto i : mp)
            current_highest_freq = max(current_highest_freq, i.second);

        long long operations = 0;
        while (current_highest_freq < n)
        {
            operations++; // to clone the array
            long long copies = current_highest_freq;
            current_highest_freq *= 2;
            if (current_highest_freq <= n)
                operations += copies; // swap all the copies
            else
                operations += n - copies; // swap only required copies
        }
        cout << operations << endl;
    }
    return 0;
}