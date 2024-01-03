#include <bits/stdc++.h>
using namespace std;

int main()
{
    // taking input
    long long n, m;
    cin >> n >> m;
    char a[n][m];

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j];
    }

    long long mod = 1e9 + 7;     // mod value
    long long differentName = 1; // storing answer

    // modulo multiplication
    // (a*b)%mod = ((a%mod)*(b%mod))%mod

    for (int i = 0; i < m; i++)
    {
        unordered_set<char> s; // storing unique character set
        for (int j = 0; j < n; j++)
            s.insert(a[j][i]);

        long long uniqueCharInColumn = s.size(); // unique characters in a column

        differentName = ((differentName % mod) * (uniqueCharInColumn % mod)) % mod;
    }

    cout << differentName << endl;
    return 0;
}