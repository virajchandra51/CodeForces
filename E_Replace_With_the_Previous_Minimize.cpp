#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        char maxPossibleCharacter = 'a';
        char notPossibleCharacter = 'a';

        for (int i = 0; i < n; i++) // O(n)
        {
            if (s[i] - 'a' > k)
            {
                notPossibleCharacter = s[i];
                break;
            }
            if (s[i] > maxPossibleCharacter)
            {
                maxPossibleCharacter = s[i];
            }
        }

        int opCountForPossibleCharacter = maxPossibleCharacter - 'a';
        int leftOpCount = k - opCountForPossibleCharacter;
        char to = notPossibleCharacter - leftOpCount;

        for (char c = notPossibleCharacter; c > to; c--) // O(26)
        {
            for (char &e : s) // O(n)
                if (e == c)
                {
                    e--;
                }
        } //O(n*26)

        for (char &ch : s) //O(n)
        {
            if (ch <= maxPossibleCharacter)
                ch = 'a';
        }

        cout << s << endl;
    }
    return 0;
}

// TC - O(26*n) ~ O(n)
// SC - O(1)