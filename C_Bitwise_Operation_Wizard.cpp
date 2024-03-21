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
        int mx_pos = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            cout << '?' << ' ' << mx_pos << ' ' << mx_pos << ' ' << i << ' ' << i << endl;
            char curr;
            cin >> curr;
            if (curr == '<')
            {
                mx_pos = i;
            }
        }
        int j = 0;
        vector<int> isPossible;
        for (int i = 0; i < n; i++)
        {
            cout << '?' << ' ' << mx_pos << ' ' << i << ' ' << mx_pos << ' ' << j << endl;
            char curr;
            cin >> curr;
            if (curr == '>')
            {
                j = i;
                isPossible.clear();
                isPossible.push_back(i);
            }
            else if (curr == '=')
            {
                isPossible.push_back(i);
            }
        }

        if (isPossible.size() == 1)
        {
            cout << '!' << ' ' << mx_pos << ' ' << j << endl;
        }

        else
        {
            int mn_pos = isPossible[0];
            for (int i = 1; i < isPossible.size(); i++)
            {
                cout << '?' << ' ' << mn_pos << ' ' << mn_pos << ' ' << isPossible[i] << ' ' << isPossible[i] << endl;
                char curr;
                cin >> curr;
                if (curr == '>')
                {
                    mn_pos = isPossible[i];
                }
            }
            cout << '!' << ' ' << mx_pos << ' ' << mn_pos << endl;
        }
    }
    return 0;
}