#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, p;
        cin >> n >> p;
        vector<pair<long long, long long> > v(n);
        for (int i = 0; i < n; i++)
        {
            long long a;
            cin >> a;
            v[i] = {0, a};
        }
        for (int i = 0; i < n; i++)
        {
            long long b;
            cin >> b;
            v[i].first = b;
        }
        sort(v.begin(), v.end());
        long long cost = p;
        long long people = 1;
        for (auto it : v)
        {
            long long b = it.second;
            long long a = it.first;
            if (a >= p)
                break;
            if (people + b > n)
            {
                cost += (n - people) * a;
                people = n;
            }
            else
            {
                cost += b * a;
                people += b;
            }
        }
        cost += (n - people) * p;
        cout << cost << endl;
    }
    return 0;
}