#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i]; // taking input

        long long aliceSum = 0;
        long long bobSum = 0;

        sort(a.begin(), a.end()); //O(nlogn)
        reverse(a.begin(), a.end());

        string turn = "A";

        for (int i = 0; i < n; i++) //O(n)
        {
            if (turn == "A")
            {
                if (a[i] % 2 == 0)
                    aliceSum += a[i];
                turn = "B";
            }
            else
            {
                if (a[i] % 2 != 0)
                    bobSum += a[i];
                turn = "A";
            }
        }

        if (aliceSum > bobSum)
            cout << "Alice" << endl;
        else if (aliceSum == bobSum)
            cout << "Tie" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}

// TC - O(nlogn)
// SC - O(1)
