#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        bool notA_S = false, notA_T = false;
        int countOfA_S = 0, countOfA_T = 0;
        while (q--)
        {
            int d, k;
            string x;
            cin >> d >> k >> x;
            for (auto it : x)
            {
                if (it != 'a')
                {
                    if (d == 2)
                        notA_T = true;
                    else
                        notA_S = true;
                }
                else
                {
                    if (d == 2)
                        countOfA_T += k;
                    else
                        countOfA_S += k;
                }
            }
            if (notA_T)
                cout<<"YES"<<endl;
            else if (notA_S)
                cout<<"NO"<<endl;
            else if (countOfA_S < countOfA_T)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        } // O(sum of lengths of all the strings x)
    }
    return 0;
}
// TC ~ O(10^5) 
// SC - O(1)