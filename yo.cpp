#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];

int knap(int n, int w, int val[], int wt[])
{
        if(memo[n][w]==-1)
{
    if(n==0 ||w==0)
    memo[n][w]= 0;
    else  if(wt[n-1]<=w)
    {
        memo[n][w]= max(knap(n-1,w,val,wt),max(val[n-1]+knap(n,w-wt[n-1],val,wt),val[n-1]+
                    knap(n-1,w-wt[n-1],val,wt)));
    }
    else
    {
        memo[n][w]=  knap(n-1,w,val,wt);
    }
    
}
    return memo[n][w];
}
int knapSack(int n, int w, int val[], int wt[])
{
    memset(memo,-1,sizeof(memo));
    return knap(n,w,val,wt);
}

int32_t main()
{
    int n;
    cin>>n;
    int wt[n];
    int vl[n];
    for(int i=0;i<n;i++)
    {
        vl[i]=i+1;
        cin>>wt[i];
    }
    cout<<knapSack(n,n,wt,vl);
    return 0;
}
