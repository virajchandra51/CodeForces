#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int countOfOnes = 0;
        for (auto it : s)
        {
            if (it == '1')
                countOfOnes++;
        }
        if (k >= countOfOnes)
        {
            int newLength = n - k;
            string a = "";
            for (int i = 0; i < newLength; i++)
                a += '0';
            cout << a << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (k <= 0)
                    break;
                if (s[i] == '1')
                {
                    s[i] = '0';
                    k--;
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}