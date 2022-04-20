#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    long long int n;
    cin>>n;
    map<long long int,long long int> mp;
    int x;
    while(cin>>x)
    {
        mp[x++];
    }
    vector<long long int> nf;
    int flag=1;
    for(int i=1;i<=sqrt(n);i++)
    {
        if((n%i)==0)
        {
            if(mp.find(i)!=mp.end() && mp.find(n/i)!=mp.end())
            continue;
            else if(mp.find(i)!=mp.end() && mp.find(n/i)==mp.end())
            {
                flag=0;
                nf.push_back(n/i);
            }
            else if(mp.find(i)==mp.end() && mp.find(n/i)!=mp.end())
            {
                flag=0;
                nf.push_back(i);
            }
            else
            {
                flag=0;
                if(n/i == i)
                nf.push_back(i);
                else
                {
                    nf.push_back(i);
                    nf.push_back(n/i);
                }
            }
        }
    }
    if(flag==1)
    cout<<1<<" "<<0<<" "<<0<<endl;
    else
    {
        sort(nf.begin(), nf.end());
        cout<<0<<" "<<nf[0]<<" "<<nf[nf.size()-1]<<endl;
    }
    return 0;
}
