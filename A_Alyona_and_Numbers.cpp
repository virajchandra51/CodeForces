#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (long long i = 1; i <= m; i++)
    {
        if (i % 5 == 0)
            c0++;
        else if (i % 5 == 1)
            c1++;
        else if (i % 5 == 2)
            c2++;
        else if (i % 5 == 3)
            c3++;
        else
            c4++;
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        long long a_dash = i % 5;
        long long need = (5 % 5 - a_dash % 5 + 5) % 5;
        if (need == 0)
            ans += c0;
        else if (need == 1)
            ans += c1;
        else if (need == 2)
            ans += c2;
        else if (need == 3)
            ans += c3;
        else
            ans += c4;
    }
    cout << ans << endl;
    return 0;
}

// tc - O(max(n,m))
// sc - O(1)
