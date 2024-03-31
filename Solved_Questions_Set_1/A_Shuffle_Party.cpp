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
        long long ans = pow(2, floor(log2(n)));
        cout << fixed << setprecision(100) << ans << endl;
    }
    return 0;
}