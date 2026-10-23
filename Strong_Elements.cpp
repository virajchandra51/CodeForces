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
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long> prefix_gcd(n);
        prefix_gcd[0] = arr[0];
        for (long long i = 1; i < n; i++)
            prefix_gcd[i] = gcd(prefix_gcd[i - 1], arr[i]);

        vector<long long> suffix_gcd(n);
        suffix_gcd[n - 1] = arr[n - 1];
        for (long long i = n - 2; i >= 0; i--)
            suffix_gcd[i] = gcd(suffix_gcd[i + 1], arr[i]);

        long long answer = 0;
        for (long long i = 0; i < n; i++)
        {
            long long gcd_excluding_i;
            if (i == 0)
                gcd_excluding_i = suffix_gcd[1];
            else if (i == n - 1)
                gcd_excluding_i = prefix_gcd[n - 2];
            else
                gcd_excluding_i = gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]);
            if (gcd_excluding_i > 1)
                answer++;
        }
        cout << answer << endl;
    }
    return 0;
}

// Time Complexity: O(n log(max(arr[i])))
// Space Complexity: O(n)