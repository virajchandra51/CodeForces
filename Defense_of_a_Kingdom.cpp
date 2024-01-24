#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll w, h, n;
        cin >> w >> h >> n; // taking input

        if (n == 0)
        {
            cout << w * h << endl;
            continue;
        } // if n==0 no towers kept hence I return whole area

        vector<long long> horizontal, vertical;
        // pushing 0 so that I can get the difference for first tower 
        horizontal.push_back(0);
        vertical.push_back(0);

        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            horizontal.push_back(x);
            vertical.push_back(y);
        }
        // pushing last+1 so that I can get the difference for last tower 
        horizontal.push_back(w + 1);
        horizontal.push_back(h + 1);

        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());
        // sort all

        ll maximumDiffHorizontal = 0;
        ll maximumDiffVertical = 0;

        for (int i = 0; i < n - 1; i++)
        {
            maximumDiffHorizontal = max(maximumDiffHorizontal, horizontal[i + 1] - horizontal[i] - 1);
            // find max diff horizontally
            maximumDiffVertical = max(maximumDiffVertical, vertical[i + 1] - vertical[i] - 1);
            // find max diff vertically
        }

        ll maxArea = maximumDiffHorizontal * maximumDiffVertical;
        // print maxArea
        
        cout << maxArea << endl;
    }
    return 0;
}