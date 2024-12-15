#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        int pos_y = 0;
        int pos_x = 0;
        reverse(x.begin(), x.end()); // 10^5
        reverse(y.begin(), y.end()); // 10^5
        for (int i = 0; i < y.size(); i++) // 10^5
        {
            if (y[i] == '1')
            {
                pos_y = i;
                break;
            }
        }
        for (int i = pos_y; i < x.size(); i++) // 10^5
        {
            if (x[i] == '1')
            {
                pos_x = i;
                break;
            }
        }
        cout << pos_x - pos_y << endl;
    }
    return 0;
}

// tc - O(10^5)
// sc - O(10^5)