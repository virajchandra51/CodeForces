#include <bits/stdc++.h>
using namespace std;

vector<int> dm(1001, 1001);

void pre()
{
    dm[1] = 0;
    for (int i = 1; i < 1001; i++)
    {
        for (int x = 1; x <= i; x++)
        {
            int j = i + i / x;
            if (j < 1001)
                dm[j] = min(dm[j], dm[i] + 1);
        }
    }
}

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {
            if (wt[i - 1] <= w)
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}

int main()
{
    pre();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += dm[b[i]];
        k = min(k, sum);
        for (int i = 0; i < n; i++)
            b[i] = dm[b[i]];
        cout << knapSack(k, b, c, n) << endl;
    }
    return 0;
}