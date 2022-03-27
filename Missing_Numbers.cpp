#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

void solve()
{
    int inputArray[4];
    rep(i,4)
    cin>>inputArray[i];

    sort(inputArray, inputArray + 4);
        
    if (inputArray[0]<0) //a<b
    {           
        if (inputArray[1]!=0)
        cout<<-1<<" "<<-1<<endl;
        else
        {
            int a = (inputArray[2] + inputArray[0]) / 2;
            int b = (inputArray[2] - inputArray[0]) / 2;
                
            int a1 = min(a, b);
            int b1 = max(a, b);

            if (a1 > 10000 || b1 > 10000) 
            cout<<-1<<" "<<-1<<endl;
            else 
            {
                if (a1 * b1 == inputArray[3]) 
                cout<<a1<<" "<<b1<<endl;
                else 
                {
                    a = (inputArray[3] + inputArray[0]) / 2;
                    b = (inputArray[3] - inputArray[0]) / 2;

                    a1 = min(a, b);
                    b1 = max(a, b);
                    if (a1 > 10000 || b1 > 10000) 
                    cout<<-1<<" "<<-1<<endl;
                    else 
                    {
                        if (a1 * b1 == inputArray[2]) 
                        cout<<a1<<" "<<b1<<endl;
                        else 
                        cout<<-1<<" "<<-1<<endl;
                    }
                }
            }
        }
    }
    else if (inputArray[0]==0) //a==b
    {    
        if (inputArray[1] != 1) 
        cout<<-1<<" "<<-1<<endl;
        else if (inputArray[1] == 1 && inputArray[2] == 1) 
        cout<<1<<" "<<1<<endl;
        else 
        {
            int a = floor(sqrt(inputArray[3]));
            int a1 = ceil(sqrt(inputArray[3]));
            if (a>10000) 
            cout<<-1<<" "<<-1<<endl;
            else 
            {
                if(a==a1 && a+a==inputArray[2]) 
                cout<<a<<" "<<a<<endl;
                else 
                cout<<-1<<" "<<-1<<endl;
            }
        }
    }
    else 
    {
        if(inputArray[2]==inputArray[1] && inputArray[2]+1==inputArray[3] && inputArray[0]==inputArray[1] - 1) //b=1
        {
            if (inputArray[2] > 10000) 
            cout<<-1<<" "<<-1<<endl;
            else 
            cout<<inputArray[2]<<" "<<1<<endl;
        }
        else 
        {
            //inputArray[1] be a - b
            int a = (inputArray[1] + inputArray[2]) / 2;
            int b = (inputArray[2] - inputArray[1]) / 2;
            
            int a1 = max(a, b);
            int b1 = min(a, b);
                
            if (a1 > 10000 || b1 > 10000) 
            cout<<-1<<" "<<-1<<endl;
            else 
            {
                if (a1 * b1 == inputArray[3] && a1/b1 == inputArray[0])
                cout<<a1<<" "<<b1<<endl;
                else 
                {
                    // inputArray[0] be a - b
                    a = (inputArray[0] + inputArray[2]) / 2;
                    b = (inputArray[2] - inputArray[0]) / 2;
                        
                    a1 = max(a, b);
                    b1 = min(a, b);
                        
                    if (a1 > 10000 || b1 > 10000) 
                    cout<<-1<<" "<<-1<<endl;
                    else 
                    {
                        if (a1 * b1 == inputArray[3] && a1/b1 == inputArray[1])
                        cout<<a1<<" "<<b1<<endl;
                        else 
                        cout<<-1<<" "<<-1<<endl;
                    }
                }
            }
        }
    }
}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}