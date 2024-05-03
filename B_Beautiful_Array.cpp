#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        long long y = (k * b);
        if (y > s)
            cout << "-1" << endl;
        else
        {
            long long rem = s - (y);
            long long z = (k - 1) * (n - 1);
            if (z >= rem)
            {
                vector<long long> arr(n, 0);
                arr[n - 1] = y;
                long long i = n - 2;
                while (rem > 0 && i >= 0)
                {
                    if (rem >= k - 1)
                    {
                        arr[i] = k - 1;
                        rem -= (k - 1);
                    }
                    else
                    {
                        arr[i] = rem;
                        rem = 0;
                    }
                    i--;
                }

                for (long long i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            else
                cout << "-1" << endl;
        }
    }
}