#include <bits/stdc++.h>
using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define rrep(i, j) for (int i = j - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()

// Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef map<int, int> mii;

void answertoProb()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> prefixA(n, 0);
    vector<int> prefixB(m, 0);
    vector<int> suffixA(n, 0);
    vector<int> suffixB(m, 0);
    prefixA[0] = a[0];
    prefixB[0] = b[0];
    suffixA[n - 1] = a[n - 1];
    suffixB[m - 1] = b[m - 1];
    for (int i = n - 2; i >= 0; i--)
        suffixA[i] = suffixA[i + 1] + a[i];
    for (int i = m - 2; i >= 0; i--)
        suffixB[i] = suffixB[i + 1] + b[i];
    for (int i = 1; i < n; i++)
        prefixA[i] = a[i] + prefixA[i - 1];
    for (int i = 1; i < m; i++)
        prefixB[i] = prefixB[i - 1] + b[i];
    int ans = -1;
    for (int i = 0; i <= n; i++)
    {
        int sum;
        if (i == 0)
        {
            sum = suffixB[m - n + i] - prefixA[n - 1];
        }
        else if (i == n)
        {
            sum = suffixA[0] - prefixB[n - 1];
        }
        else
            sum = suffixA[n - i] + suffixB[m - n + i] - prefixA[n - i - 1] - prefixB[i - 1];
        ans = max(sum, ans);
    }
    cout << ans << endl;
}

int32_t main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        answertoProb();
    }
    return 0;
}