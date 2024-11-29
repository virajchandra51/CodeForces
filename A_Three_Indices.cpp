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
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        int flag = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
            {
                cout << "YES" << endl;
                cout << i << " " << i + 1 << " " << i + 2 << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
    }
    return 0;
}