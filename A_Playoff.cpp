#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin>>n;
    long long ans = 1;
    for(int i=1;i<=n;i++) ans*=2;
    cout<<ans-1<<endl;
}

// tc - O(n)

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

