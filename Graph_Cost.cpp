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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        stack<long long> values;
        stack<long long> nodes;
        long long cost = 0;

        for (int i = 0; i < n; i++)
        {
            while (values.size() > 1 && values.top() > a[i])
            {
                long long v1 = values.top();
                values.pop();
                if (v1 >= values.top())
                {
                    nodes.pop();
                }
                else
                {
                    values.push(v1);
                    break;
                }
            }
            values.push(a[i]);
            nodes.push(i);
        } // n

        long long last = values.top();
        values.pop();
        long long j = nodes.top();
        nodes.pop();

        while (!values.empty())
        {
            cost += max(last, values.top()) * (j - nodes.top());
            last = values.top();
            values.pop();
            j = nodes.top();
            nodes.pop();
        } // n
        cout << cost << endl;

        // tc - O(n)
        // sc - O(n)
    }
    return 0;
}