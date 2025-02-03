#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long w, h;
        cin >> w >> h;
        long long area = INT_MIN;
        for (int i = 0; i < 4; i++)
        {
            long long k;
            cin >> k;
            long long first, last;
            for (int j = 0; j < k; j++)
            {
                long long x;
                cin >> x;
                if (j == 0)
                    first = x;
                if (j == k - 1)
                    last = x;
            }
            area = max(area, (last - first) * (i <= 1 ? h : w));
        }
        cout << area << endl;
    }
    return 0;
}