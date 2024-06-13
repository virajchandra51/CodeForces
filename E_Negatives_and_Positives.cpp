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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long c = 0;
        for (auto it : a)
        {
            if (it < 0)
                c++;
        }
        if (c & 1)
        {
            long long s = 0;
            for (auto it : a)
                s += (abs(it));
            long long m = INT_MAX;
            for (auto it : a)
                m = min(m, abs(it));
            s -= (2 * m);
            cout << s << endl;
        }
        else
        {
            long long s = 0;
            for (auto it : a)
                s += (abs(it));
            cout << s << endl;
        }
    }
    return 0;
}