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
        int aliceScore = 0;
        int bobScore = 0;
        int countOfOne = 0;
        int countOfTwos = 0;
        int sum = 0;
        for (auto it : a) // n
        {
            if (it == 1)
                countOfOne++;
            else
            {
                sum += (it - 2);
                countOfTwos++;
            }
        }

        string turn = "alice";

        if (countOfOne > 0)
        {
            if (countOfOne & 1)
            {
                aliceScore += ((countOfOne + 1) / 2);
                bobScore += (countOfOne / 2);
                turn = "bob";
            }
            else
            {
                aliceScore += (countOfOne / 2);
                bobScore += (countOfOne / 2);
                turn = "alice";
            }
        }

        if (sum & 1)
        {
            if (turn == "alice")
                turn = "bob";
            else
                turn = "alice";
        }

        if (turn == "alice")
            bobScore += (countOfTwos);
        else
            aliceScore += (countOfTwos);

        if (aliceScore > bobScore)
            cout << "Alice" << endl;
        else if (aliceScore < bobScore)
            cout << "Bob" << endl;
        else
            cout << "Draw" << endl;
    }
    // tc - O(n)
    // sc - O(1)
    return 0;
}