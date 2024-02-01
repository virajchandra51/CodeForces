#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)cin >> a[i];for (int i = 0; i < n; i++)cin >> b[i];
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {v[i].first = a[i];v[i].second=b[i];}
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) cout<<v[i].first<<" ";cout<<endl;
        for(int i = 0; i < n; i++) cout<<v[i].second<<" ";cout<<endl;
    }
}
