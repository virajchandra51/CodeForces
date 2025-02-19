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
        map<long long, long long> mp;
        for (long long i = 0; i < n; i++) // n 
        {
            cin >> a[i];
            mp[a[i]]++; // logn
        }
        
        for (auto &i : mp) // n
        {
            if (i.first == 0)
                continue;
            mp[0] += (i.second / 2); // logn
            i.second = i.second % 2;
        }

        long long smallest_length = 0;
        for (auto &i : mp) // n
        {
            if (i.first == 0 && i.second > 0)
                smallest_length++;
            else
                smallest_length += i.second;
        }
        cout << smallest_length << endl;
    }
    return 0;
}

// tc = O(NlogN) = O(2*10^5log2*10^5) = O(2*10^5*17) = O(3.4*10^6)
// sc = O(N) = O(2*10^5)