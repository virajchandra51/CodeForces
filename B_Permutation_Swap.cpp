#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int g = abs(a[0] - 1);
        for (int i = 1; i < n; i++)
        {
            g = gcd(g, abs(a[i] - (i + 1)));
        }
        cout << g << endl;
    }
    return 0;
}
