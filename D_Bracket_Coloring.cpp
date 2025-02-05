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
        if (n % 2 == 1 || count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')'))
        {
            cout << "-1" << endl;
            continue;
        }
        vector<int> arr(n);
        int cnt = 0;
        int pos, neg;
        pos = 1, neg = 2;
        if (s[0] == ')')
            pos = 2, neg = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                cnt++;
                if (cnt > 0)
                    arr[i] = pos;
                else
                    arr[i] = neg;
            }
            else
            {
                cnt--;
                if (cnt < 0)
                    arr[i] = neg;
                else
                    arr[i] = pos;
            }
        }
        if (*max_element(arr.begin(), arr.end()) == *min_element(arr.begin(), arr.end()))
        {
            cout << "1" << endl;
            for (auto &it : arr)
                cout << it << ' ';
            cout << endl;
        }
        else
        {
            cout << "2" << endl;
            for (auto &it : arr)
                cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}