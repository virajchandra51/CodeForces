#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // a = guest.length(), b = residence.length(), c = pile.length()
    string guest, residence, pile;
    cin >> guest >> residence >> pile;

    string combined = guest + residence;

    sort(combined.begin(), combined.end());
    sort(pile.begin(), pile.end());

    if (combined == pile)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

// Time Complexity: O(a + b + c + (a+b)*log(a+b) + c*log(c)) = O(200*log(200))
// Space Complexity: O(a + b + c)