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
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];
        unordered_map<long long, long long> freq;
        for (long long i = 0; i < n; i++) // n
            freq[a[i]]++;

        int flag = 0;
        for (auto i : freq)
        {
            if (i.second > 1)
                flag = 1;
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}