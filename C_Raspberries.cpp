#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];

        if (k == 4)
        {
            int even_count = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 0)
                    even_count++;
            }

            int ans = min(0, 2 - even_count);

            cout << ans << endl;
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % k == 0)
                    flag = 1;
            }
            if(flag)
        }

        return 0;
    }
}