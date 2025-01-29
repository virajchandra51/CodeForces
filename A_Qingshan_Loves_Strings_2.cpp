#include <iostream>
#include <string>
#include <vector>
using namespace std;
int calc_same(string s)
{
    int same = 0;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] == s[s.size() - i - 1])
            same++;
    }
    return same;
}
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
        if (n % 2 == 1)
            cout << "-1" << endl;
        else
        {
            vector<int> temp;
            int i;
            for (i = 1; i <= 300; i++)
            {
                int prev_same = calc_same(s);
                bool inserted = false;
                for (int j = 0; j < s.size() / 2; j++)
                {
                    if (s[j] == '0' && s[s.size() - j - 1] == '0')
                    {
                        temp.push_back(s.size() - j);
                        s.insert(s.begin() + s.size() - j, '0');
                        s.insert(s.begin() + s.size() - j, '1');
                        inserted = true;
                        break;
                    }
                    else if (s[j] == '1' && s[s.size() - j - 1] == '1')
                    {
                        temp.push_back(j);
                        s.insert(s.begin() + j, '0');
                        s.insert(s.begin() + j, '1');
                        inserted = true;
                        break;
                    }
                }

                int curr_same = calc_same(s);
                if (curr_same == 0)
                {
                    cout << s << endl;
                    cout << temp.size() << endl;
                    for (int k = 0; k < temp.size(); k++)
                        cout << temp[i] << " ";
                    cout << endl;
                    break;
                }
                if (!inserted || curr_same > prev_same)
                {
                    cout << "-1" << endl;
                    break;
                }
            }
            if (i == 301)
                cout << "-1" << endl;
        }
    }
}