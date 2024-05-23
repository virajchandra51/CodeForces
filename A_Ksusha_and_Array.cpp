#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) // n
        cin >> a[i];

    long long m = INT_MAX;
    for (int i = 0; i < n; i++) // n
        m = min(m, a[i]);

    long long flag = 1;
    for (int i = 0; i < n; i++) // n
    {
        if (a[i] % m != 0)
            flag = 0;
    }

    if (flag)
        cout << m << endl;
    else
        cout << -1 << endl;

    return 0;
}

// tc - O(n)
// sc - O(n)