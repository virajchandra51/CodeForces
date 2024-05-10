#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,k,q;
        cin>>n>>k>>q;
        vector<long long> a(k);
        for(int i=0;i<k;i++)
            cin>>a[i];
        vector<long long> b(k);
        for(int i=0;i<k;i++)
            cin>>b[i];
        for(int i=0;i<q;i++) // q
        {
            long long d;
            cin>>d;
            auto it = lower_bound(a.begin(),a.end(),d)-a.begin(); // logk
            it--;
            if(it==-1)
            {
                long long dist = a[0];
                long long time = b[0];
                cout<<(d*time)/dist<<" ";
            }
            else
            {
                long long dist = a[it+1]-a[it];
                long long time = b[it+1]-b[it];
                cout<<((d-a[it])*time)/dist+b[it]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

// tc - O(q*log(k))
// sc - O(k)