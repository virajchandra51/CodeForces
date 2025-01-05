#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) // n
        cin >> v[i];
    int sum = 0;
    for (int i = 0; i < n; i++) // n
        sum += v[i] - 1;
    cout << sum << endl;
    return 0;
}

// tc - O(n) = O(3000)
// sc - O(n) = O(3000)