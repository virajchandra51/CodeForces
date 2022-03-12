#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n]; ll ts=0;
        rep(i,n) {cin>>a[i];ts+=a[i];}

        sort(a,a+n);

        ll sumb = a[0]; ll sumr= 0; int index1=1;int index2=n-1;
int f = 0;
        while(index1<index2)
        {
            sumb += a[index1];
            sumr +=a[index2];
            if(sumr>sumb)
            {
                f=1;break;
            }
            index1++;index2--;

        }

    if(f==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    }
    return 0;
}