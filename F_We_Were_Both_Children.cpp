#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // taking inputs
        int n;
        cin >> n;
        vector<int> hopLength(n);
        for (int i = 0; i < n; i++)
            cin >> hopLength[i];
        vector<int> freq(200001, 0);
        for (int i = 0; i < n; i++)
            freq[hopLength[i]]++;

        vector<int> trappedFrogs(n + 1, 0); // this is representing count of frogs for each trap coordinate i

        for (int h = 1; h <= n; h++)
        {
            for (int i = h; i <= n; i += h)
            {
                trappedFrogs[i] += freq[h];
            }
        }

        int answer = 0;
        for (int i = 1; i <= n; i++)
        {
            answer = max(answer, trappedFrogs[i]);
        }

        cout << answer << endl;
    }
    return 0;
}