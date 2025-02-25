#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l = INT_MAX;
        int ans_a = 1;
        int ans_b = n - 1;
        for (int fac = 2; fac * fac <= n; fac++) // sqrtn
        {
            if (n % fac == 0)
            {
                int a = n / fac;
                int b = n - a;
                if (l > lcm(a, b))
                {
                    l = lcm(a, b);
                    ans_a = a;
                    ans_b = b;
                }
            }
        }
        cout << ans_a << " " << ans_b << endl;
    }
    return 0;
}

// tc - O(sqrt(10^9)) = O(10^4)
// sc - O(1)