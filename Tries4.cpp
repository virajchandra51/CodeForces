#include <bits/stdc++.h>
using namespace std;

int checkBit(int pattern, vector<int> &a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & pattern) == pattern)
        {
            count++;
        }
    }
    return count;
}

int maxAND(vector<int> arr, int n)
{
    int res = 0;
    int count = 0;
    for (int bit = 31; bit >= 0; bit--)
    {
        count = checkBit(res | (1 << bit), arr, n);
        if (count >= 2)
        {
            res = res | (1 << bit);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Maximum AND value: " << maxAND(arr, n);
    return 0;
}

// TC - O(n*32)
// SC - O(n)
