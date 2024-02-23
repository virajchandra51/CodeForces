#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++) // n
        cin >> a[i];

    map<long long, long long> m;
    m[0] = 1;

    long long preS = 0;
    for (int i = 0; i < n; i++) // n
    {
        preS += a[i];
        m[(preS % n + n) % n]++; // logn
    } // nlogn

    long long answer = 0;
    for (auto it : m) // n
    {
        answer += (it.second * (it.second - 1) / 2);
    }
    cout << answer << endl;

    return 0;
}

// tc - O(nlogn) - 10^5~10^6
// sc - O(n)
