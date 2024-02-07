#include <bits/stdc++.h>
using namespace std;

int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long n, k;
        cin >> n >> k;
        vector<long> ans(n, 0);
        long flag = 0; long index = 1;
        for (int i = 0; i < k; i++)
        {
            if (!flag)
            {
                long ind = i;
                while (ind + k < n)
                    ind += k;
                for (ind; ind >= i; ind -= k)
                {
                    ans[ind] = index;
                    index++;
                }
            }
            else
            {
                for (long ind = i; ind < n; ind += k)
                {
                    ans[ind] = index;
                    index++;
                }
            }
            if (flag)
                flag = 0;
            else
                flag = 1;
        }
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}