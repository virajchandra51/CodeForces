#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[62630];
int k = 0;
int m = 1e9 + 7;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if ((n * (n + 1)) % 4 != 0)
        {
            cout << 0 << endl;
        }
        else
        {
            k = (n * (n + 1)) / 4;
            memset(dp, 0, sizeof(dp));

            dp[0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = k; j >= 0; j--)
                {

                    if (j - i >= 0)
                    {
                        dp[j] = (dp[j] + dp[j - i]) % m;
                        // cout<<dp[j]<<" ";
                    }
                }
                // cout<<endl;
            }
            cout << (dp[k] % m * ((m + 1) / 2)) % m << endl;
        }
    }

    return 0;
}