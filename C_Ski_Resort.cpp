#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k, q;
        cin >> n >> k >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];

        for (int i = 0; i < n; i++)
        {
            if (a[i] > q)
                a[i] = 0;
            else
                a[i] = 1;
        }

        long long count_of_1s = 0;
        long long ways = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                count_of_1s++;
            else
            {
                if (count_of_1s >= k)
                {
                    long long diff = count_of_1s - k + 1;
                    ways += (diff * (diff + 1)) / 2;
                }
                count_of_1s = 0;
            }
        }
        if (count_of_1s >= k)
        {
            long long diff = count_of_1s - k + 1;
            ways += (diff * (diff + 1)) / 2;
        }
        cout << ways << endl;
    }
    return 0;
}