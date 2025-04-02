#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n; // number of fence planks
        int m;       // number of available colors
        cin >> n >> m;

        vector<long long> a(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        // Compute L and R for each color.
        vector<long long> L(m), R(m);
        for (int i = 0; i < m; i++)
        {
            L[i] = min(a[i], n - 1LL);
            R[i] = max(1LL, n - a[i]);
        }

        // Sort copies of L and R for the "two-pointer" / prefix sum approach
        vector<long long> X = L, Y = R;
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        // Prefix sum of Y for summing quickly
        vector<long long> prefixY(m + 1, 0LL);
        for (int i = 0; i < m; i++)
        {
            prefixY[i + 1] = prefixY[i] + Y[i];
        }

        // Sum of f(i,j) over all i, j (including i=j for now)
        long long total = 0;
        int j = 0; // pointer for Y
        for (int i = 0; i < m; i++)
        {
            long long xVal = X[i];
            // Move j so that Y[j] <= xVal
            // i.e., we want the largest j such that Y[j] <= xVal
            // We can do this with a while loop or binary search (upper_bound).
            // Here we'll use binary search for clarity:
            int p = int(upper_bound(Y.begin(), Y.end(), xVal) - Y.begin());
            // p is the count of Y[j] <= xVal

            if (p > 0)
            {
                // sum_{k=1..p} ( xVal - Y[k] + 1 )
                // = p*(xVal + 1) - sum(Y[1..p])
                long long sumOfY = prefixY[p]; // sum of first p Y's
                total += p * (xVal + 1) - sumOfY;
            }
        }

        // Now subtract the diagonal part f(i,i) for i=1..m
        // f(i,i) = max( 0, L[i] - R[i] + 1 )
        long long diag = 0;
        for (int i = 0; i < m; i++)
        {
            long long val = L[i] - R[i] + 1;
            if (val > 0)
            {
                diag += val;
            }
        }

        // We only want i != j, so subtract any diagonal terms
        long long answer = total - diag;

        cout << answer << "\n";
    }

    return 0;
}