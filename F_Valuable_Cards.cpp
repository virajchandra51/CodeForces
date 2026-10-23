#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;

        vector<long long> a(n);
        for (long long i = 0; i < n; ++i)
            cin >> a[i];

        vector<long long> cards;
        for (long long i = 0; i < n; ++i)
        {
            if (x % a[i] == 0)
                cards.push_back(a[i]);
        }

        vector<long long> divisors;
        for (long long i = 1; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                divisors.push_back(i);
                if (i != x / i)
                    divisors.push_back(x / i);
            }
        }

        vector<bool> canMake(x + 1, false);
        canMake[1] = true;

        int segments = 1;

        for (long long c : cards)
        {
            vector<long long> newCanMake;
            bool buildX = false;

            for (auto d : divisors)
            {
                if (!canMake[d])
                    continue;
                long long newNumber = d * c;
                if (newNumber == x)
                {
                    buildX = true;
                    break;
                }
                newCanMake.push_back(newNumber);
            }

            if (buildX)
            {
                segments++;
                canMake.assign(x + 1, false);
                canMake[1] = true;
                canMake[c] = true;
            }
            else
            {
                for (auto newNumber : newCanMake)
                {
                    if (newNumber <= x)
                        canMake[newNumber] = true;
                }
            }
        }

        cout << segments << endl;
    }

    return 0;
}

// Time Complexity: O(n * 128)
// Space Complexity: O(n)