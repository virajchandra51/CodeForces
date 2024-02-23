#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    map<string, long long> m;

    for (int i = 0; i < n; i++) // n
    {
        string s;
        cin>>s;
        if(m.find(s) != m.end()) // logn
        {
            m[s]++; // logn
            cout<<s<<m[s]<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
            m[s]=0; // logn
        }
    } // nlogn

    return 0;
}

// tc - O(nlogn) - 10^5~10^6
// sc - O(n)
