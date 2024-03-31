#include <bits/stdc++.h>
using namespace std;

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        vector<long> a(n);
        for (long i = 0; i < n; i++)
            cin >> a[i];
        vector<char> ans(n,'a');
        map<int, stack<char> > m;
        char ch = 'a';
        ans[0] = ch;
        ch++;
        m[0].push('a');
        for (int i = 1; i < n; i++)
        {
            if (a[i] == 0)
            {
                m[0].push(ch);
                ans[i] = ch;
                ch++;
            }
            else
            {
                char c = m[a[i] - 1].top();
                m[a[i] - 1].pop();
                ans[i] = c;
                m[a[i]].push(c);
            }
        }
        for (auto it : ans)
            cout << it;
        cout << endl;
    }
    return 0;
}