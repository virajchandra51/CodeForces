#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> v = {"0", "1"};
    for (int i = 2; i <= n; i++) // O(n)
    {
        int end = v.size()-1;
        while(end>=0) // O(2^(i-1))
        {
            v.push_back(v[end]);
            end--;
        }
        int count = pow(2,i);
        for(int j=1;j<=count;j++) // O(2^i)
        {
            if(j<=(count/2)) v[j-1] = "0"+v[j-1];
            else v[j-1] = "1"+v[j-1];
        }
    }
    for(auto it:v) cout<<it<<endl;
    return 0;
}
// TC - O(n * 2^(n)) ~ O(16*65536) ~ O(10^6)
// SC - O(2^n)