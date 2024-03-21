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
        int countOfOne = 0;
        for (auto it : s) // n
            if (it == '1')
                countOfOne++; 
        int zeroSegment = 0;
        int maxZeroSegment = 0;
        for (auto it : s) // n
        {
            if (it == '0')
                zeroSegment++;
            else
            {
                maxZeroSegment = max(maxZeroSegment, zeroSegment);
                zeroSegment = 0;
            }
        }
        maxZeroSegment = max(maxZeroSegment, zeroSegment);
        cout << maxZeroSegment + countOfOne << endl;
    }
    // tc - O(n)
    // sc - O(1)
    return 0;
}