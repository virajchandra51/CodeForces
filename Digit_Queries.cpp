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
        n--;
        if (n < 9)
            cout << (int)n + 1 << endl;
        else
        {
            int len = 1;
            while (9 * pow(10, len - 1) * len < n)
            {
                n -= 9 * pow(10, len - 1) * len;
                len++;
            }
            string S = to_string(pow(10, len - 1) + n / len);
            cout << (int)(S[n % len] - '0') << endl;
        }
    }
    return 0;
}