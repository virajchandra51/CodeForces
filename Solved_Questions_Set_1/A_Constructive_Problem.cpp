#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // taking input

        map<int, int> mp;

        for (auto it : a) // O(n)
            mp[it]++; // O(logn)
        // O(nlogn)
        // frequency map

        int mex = 0;
        for (auto it : mp) //O(n)
        {
            if (it.first == mex) 
                mex++;
            else
                break;
        } // finding current mex

        int targetMex = mex + 1; // mex I want to make

        
        int l = -1;
        int r = -1;
        for (int i = 0; i < n; i++)  //O(n)
        {
            if (a[i] == targetMex)
            {
                if (l == -1)
                    l = i;
                r = i;
            }
        } // I find the left end and right end of the mex+1 value

        // if l is not equal to -1
        // means I found a segment l..r where value at index
        // l and r both is mex+1
        if (l != -1)
        {
            // convert the whole segment to mex
            // so that I remove mex+1 from the array completely
            for (int i = l; i <= r; i++)
                a[i] = mex;

            // now I check again that in doing this am I still getting mex 
            // of array as mex+1???
            map<int, int> mp;
            for (auto it : a)
                mp[it]++;
            // O(nlogn)
            int newMex = 0;
            for (auto it : mp)
            {
                if (it.first == newMex)
                    newMex++;
                else
                    break;
            }

            if(newMex == targetMex) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;

        }
        // if the array has no mex+1 value in it
        else
        {
            // I need to find some value less than mex which has freq>1
            // or I need to find some value greater than mex+1
            int flag = 0;
            for(auto it : mp)
            {
                if(it.first<mex && it.second>1) flag = 1;
                if(it.first>mex+1) flag = 1;
            }
            // if flag == 1 means yes
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl; 
        }
    }
    return 0;
}

// TC - O(nlogn)
// SC - O(n)