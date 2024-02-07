#include <bits/stdc++.h>
using namespace std;

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long n, m, k;
        cin >> n >> m >> k;
        vector<long> a(n), b(m);
        set<long> setForA, setForB;
        for (long i = 0; i < n; i++)
            cin >> a[i];
        for (long i = 0; i < m; i++)
            cin >> b[i];
        for (auto it : a)
            setForA.insert(it);
        for (auto it : b)
            setForB.insert(it);
        long a2 = 0, b2 = 0, c2 = 0;
        for (long i = 0; i < k; i++)
        {
            if (setForA.find(i + 1) != setForA.end())
                a2++;
            if (setForB.find(i + 1) != setForB.end())
                b2++;
            if (setForA.find(i + 1) != setForA.end() && setForB.find(i + 1) != setForB.end())
                c2++;
        }
        int flag = 0;
        if (a2 + b2 - c2 >= k && b2 >= k / 2 && a2 >= k / 2) flag=1;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}