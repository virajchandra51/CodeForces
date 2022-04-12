#include<bits/stdc++.h>
using namespace std ;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define rep(i,a,b) for (int i=a;i<b;i++)
#define ll long long 



int main (){
    
    fastio();

    int t=1 ;
    // cin>>t ;
    while (t--){
        int n , k ;
        cin>> n>> k ;
        vector <int> a (n);
        rep (i,0,n)cin>>a[i];
        int ans =0;
        vector <int>hash (2e5+1 , 0 );
        
        rep (i,0,n)hash[a[i]]++;
        rep(i,0,10)cout<<hash[i]<<" ";
        cout<<endl;
        int sum =0;
        for (int i = 10;i>0 ;i--){
            if (i!=2e5 )
            {
                hash[i]+=hash[i+1];
            }
            if (hash[i]==n)break;
            if (sum + hash[i]>k){
                sum = hash[i];
                ans ++;
                cout<<sum<<" "<<"if block"<<endl;

            }
            else 
            {
                sum +=hash[i];
                cout<<sum<<" "<<"else block"<<endl;
            }
        }
        rep(i,0,10)cout<<hash[i]<<" ";
        cout<<endl;
        if (sum !=0 )ans ++;
        cout << ans << "\n";

    }
}
