#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    // start with index 1 since s[0] has no previous character
    // and we need to check if s[i] is equal to s[i-1]

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            // possible character to replace s[i]
            char ch;

            // checking all characters from a to z
            for (char c = 'a'; c <= 'z'; c++)
            {
                // if s[i] is not equal to s[i-1] and s[i] is not equal to s[i+1]
                if (c != s[i] && (i + 1 == n || c != s[i + 1]))
                {
                    ch = c;
                    break;
                }
            }

            // replace s[i] with ch
            s[i] = ch;
        }
    }

    // print the final string
    cout << s << endl;
    return 0;
}