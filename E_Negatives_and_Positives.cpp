#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long countOfNeg = 0;
        for (auto it : a)
        {
            if (it < 0)
                countOfNeg++;
        }

        if (countOfNeg % 2 == 1)
        {
            long long sum = 0;
            for (auto it : a)
                sum += (abs(it));

            long long m = INT_MAX;
            for (auto it : a)
                m = min(m, abs(it));

            sum -= (2 * m);
            cout << sum << endl;
        } // odd
        else
        {
            long long sum = 0;
            for (auto it : a)
                sum += (abs(it));
            cout << sum << endl;
        } // even
    }
    return 0;
}

// TC - O(n)
// SC - O(n)