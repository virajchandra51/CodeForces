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
        string s;
        cin >> s;
        long long sum = 0;
        long long ops = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
                sum--;
            else
                sum++;
            if (sum < 0)
            {
                ops++;
                sum = 0;
            }
        }
        cout << ops << endl;
    }
    return 0;
}