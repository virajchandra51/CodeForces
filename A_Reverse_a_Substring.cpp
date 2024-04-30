#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]>s[i+1])
        {
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<i+2<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

// tc - O(n)

int main()
{
    int t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}

