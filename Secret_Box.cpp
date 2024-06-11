#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, z, k;
        cin >> x >> y >> z >> k;
        long long ans = 0;
        for (long long a = 1; a <= x; a++)
        {
            for (long long b = 1; b <= y; b++)
            {
                long long flag1 = 0;
                long long flag2 = 0;
                if (k % (a * b) == 0)
                    flag1 = 1;
                if (k / (a * b) <= z)
                    flag2 = 1;
                if (flag1 && flag2)
                {
                    long long side1 = a;
                    long long side2 = b;
                    long long side3 = k / (a * b);

                    long long distinctPlaces = (x - side1 + 1);
                    distinctPlaces *= (y - side2 + 1);
                    distinctPlaces *= (z - side3 + 1);

                    ans = max(ans, distinctPlaces);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// TC - O(x*y) - 4*10^6
// SC - O(1)