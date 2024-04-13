#include <bits/stdc++.h>
// jai sri ram har har mahadev hare krishna om sairam
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
        int t;
        cin >> t;
        while (t--)
        {
            int cnt=1;
            int oddcnt=0;
         string s;cin>>s;
         for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                cnt++;
            }
            if(s[i-1]!=s[i]){
                oddcnt++;
            }
         }
         if(cnt==s.length()){
            cout<<"NO"<<endl;
         }else if(oddcnt==2){
            cout<<"NO"<<endl;
         }
         else{
            cout<<"YES"<<endl;
         }


        }
    }

}