#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> v(n + 1, 0), u(n + 1, 0);

    v[1] = a[0];
    for (long long i = 2; i <= n; i++) // n
        v[i] = v[i - 1] + a[i - 1];

    sort(a.begin(), a.end()); //nlogn

    u[1] = a[0];
    for (long long i = 2; i <= n; i++) // n
        u[i] = u[i - 1] + a[i - 1];

    long long q;
    cin >> q;
    while (q--) // q
    {
        long long questionType, l, r;
        cin >> questionType >> l >> r;
        if (questionType == 1)
            cout << v[r] - v[l - 1] << endl; //1
        else
            cout << u[r] - u[l - 1] << endl; //1
    }
    return 0;
}

// tc - O(n+nlogn+n+q) ~ O(nlogn) ~ 10^5
// sc - O(n+n) ~ o(n)