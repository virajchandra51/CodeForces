#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
string x = "";
void f(int k, string &s)
{
    if (k == s.size())
    {
        if (x.size())
            ans.push_back(x);
        return;
    }
    f(k + 1, s);
    x.push_back(s[k]);
    f(k + 1, s);
    x.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ans.clear();
    string s;
    cin >> s;
    f(0, s);
    sort(ans.begin(), ans.end());
    for (int i=0;i<ans.size();i++)
        cout << ans[i] << "\n";

    return 0;
}