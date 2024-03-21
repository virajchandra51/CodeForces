#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        if ((r - l + 1) % 2 == 0)
        {
            for (int i = l; i <= r; i += 2)
                cout << i + 1 << " " << i << " ";
            cout << endl;
        }
        else
        {
            if (r % 2 == 0)
                cout << -1 << endl;
            else
            {
                for (int i = l; i <= (r - 3); i += 2)
                    cout << i + 1 << " " << i << " ";
                cout << r - 1 << " " << r << " " << r - 2 << endl;
            }
        } // tc - n
        // sc - 1
    }
    return 0;
}