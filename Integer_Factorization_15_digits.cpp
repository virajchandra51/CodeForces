#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = -1;
    while(n!=0)
    {
        cin>>n;
        if(n==0) break; // end of test cases

        map<long long,long long> m;

        while(n%2==0)
        {
            n/=2;
            m[2]++;
        }
        for(long long i = 3; i*i<=n; i+=2)
        {
            while(n%i==0)
            {
                n/=i;
                m[i]++;
            }
        }
        if(n>2)
        {
            m[n]++;
        }

        for(auto it:m) cout<<it.first<<"^"<<it.second<<" ";
        cout<<endl;
    }
    return 0;
}

//TC - O(sqrt(n))
//SC - O(number of factors which are there for N)