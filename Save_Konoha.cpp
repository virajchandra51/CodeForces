#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, z;
        cin >> n >> z;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // taking input 

        multiset<int> m;
        for (int i = 0; i < n; i++) // O(n)
            m.insert(a[i]); // O(logn)
        
        int attack = 0;
        while (m.size() > 0 && z > 0) // O(n)
        {
            int attackVal = *m.rbegin();
            z -= attackVal;
            m.erase(*m.rbegin()); // O(logn)
            if (attackVal / 2 > 0)
                m.insert(attackVal / 2); //O(logn)
            attack++;
        }
        if (z <= 0)
            cout << attack << endl;
        else
            cout << "Evacuate" << endl;
    }
    return 0;
}

// TC - O(nlogn) ~ 10^5 to 10^6
// SC - O(n)
