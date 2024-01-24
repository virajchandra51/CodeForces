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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // taking input

        sort(a.begin(), a.end());
        // sort initial given factors

        long long x = a[0] * a[n - 1];
        // find X

        vector<long long> factors;

        for (long long i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if ((x / i) == i)
                    factors.push_back(i);
                else
                {
                    factors.push_back(i);
                    factors.push_back(x / i);
                }
            }
        }
        sort(factors.begin(), factors.end());
        // sort and get factors of guessed X

        if (factors == a) // if the factors array is same as given
            cout << x << endl;
        else
            cout << -1 << endl;
            
    }
    return 0;
}

// time complexity - O(nlogn + sqrt(a[0]*a[n-1])) - O(Sorting + Factor finding) ~ 10^4
// space complexity - O(n)