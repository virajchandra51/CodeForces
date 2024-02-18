#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> v(n);

    for (auto &it : v)
        cin >> it;

    sort(v.begin(), v.end()); // nlogn

    deque<long long> d;
    long long alarmOff = 0;

    for (long long i = 0; i < n; ++i) // n 
    {
        long long x = v[i];
        d.push_back(x); // 1
        while (x >= d.front() + m)
            d.pop_front(); // 1
        while (d.size() >= k)
        {
            alarmOff++;
            d.pop_back(); // 1
        }
    } // 2n = n+n = n

    cout << alarmOff << endl;
}
// TC - O(nlogn+2n) ~ O(nlogn)
// SC - O(n)