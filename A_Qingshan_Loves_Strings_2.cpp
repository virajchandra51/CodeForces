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
        string s;
        cin >> s;

        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.length(); ++i) // O(n)
        {
            cnt0 += s[i] == '0';
            cnt1 += s[i] == '1';
        }

        if (cnt0 != cnt1) // not possible
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> answer;
        deque<char> characters;

        for (int i = 0; i < s.length(); ++i) //O(n)
            characters.push_back(s[i]); //O(1)

        int d = 0;
        while (!characters.empty()) //O(n)
        {
            if (characters.front() == characters.back())
            {
                if (characters.front() == '0')
                {
                    characters.push_back('0');
                    characters.push_back('1');
                    answer.push_back(n - d);
                }
                else
                {
                    characters.push_front('1');
                    characters.push_front('0');
                    answer.push_back(0 + d);
                }
                n+=2;
            }
            while (!characters.empty() && characters.front() != characters.back())
            {
                characters.pop_back();
                characters.pop_front();
                ++d;
            }
        }

        cout << answer.size() << endl;
        if (answer.size() == 0)
        {
            cout << endl;
            continue;
        }
        for (auto it : answer) //O(n)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// TC - O(n)
// SC - O(n)