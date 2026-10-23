#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long diff = a - b;
        long long checker = a + b;
        bool flag = true;
        for (long long i = 2; i * i <= checker; i++)
        {
            if (checker % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag && diff == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// Time Complexity: O(sqrt(a + b))
// Space Complexity: O(1)