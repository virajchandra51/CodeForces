#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        vector<int> zeroes;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zeroes.push_back(i + 1);
            }
        }
        int i = 0, j = k, z = 0;
        int mn = INT_MAX;
        while (j < zeroes.size())
        {
            while (max(zeroes[z] - zeroes[i], zeroes[j] - zeroes[z]) > max(zeroes[z + 1] - zeroes[i], zeroes[j] - zeroes[z + 1]))
            {
                z++;
            }
            int m = max(zeroes[z] - zeroes[i], zeroes[j] - zeroes[z]);
            mn = min(mn, m);
            i++;
            j++;
        }
        cout << mn << endl;
    }
}