#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

long long arr1[100009], arr2[100009], arr3[100009], arr4[100009];
vector<int> v[100009];
queue<int> q;

void solve()
{
    long long n, pi, xxxxxxxxxx, xxxxxxxxxxx, xxxxxxxxxxxx = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = 0;
        v[i].clear();
    }
    for (int i = 1; i <= n; i++) 
    cin >> arr1[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> pi;
        arr2[i] = pi;
        v[pi].pb(i);
        arr4[pi]++;
    }
    for (int i = 0; i <= n; i++) if (arr4[i] == 0) q.push(i);
    while (!q.empty())
    {
        pi = q.front();
        q.pop();
        xxxxxxxxxx = 1 << 30;
        for (int i = 0; i < v[pi].size(); i++)
        {
            if (arr3[v[pi][i]] < xxxxxxxxxx)
            {
                xxxxxxxxxx = arr3[v[pi][i]];
                xxxxxxxxxxx = i;
            }
        }
        if (xxxxxxxxxx == 1 << 30) xxxxxxxxxx = 0;
        for (int i = 0; i < v[pi].size(); i++) if (i != xxxxxxxxxxx) xxxxxxxxxxxx += arr3[v[pi][i]];
        arr3[pi] = max(arr1[pi], xxxxxxxxxx);
        arr4[arr2[pi]]--;
        if (arr4[arr2[pi]] == 0) q.push(arr2[pi]);
    }
    cout << xxxxxxxxxxxx + arr3[0] << "\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

