#include <bits/stdc++.h>
using namespace std;

static bool compare(pair<long long, long long> &a, pair<long long, long long> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main()
{
    long long n;
    cin >> n;
    vector<pair<long long, long long> > v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    // taking input

    sort(v.begin(), v.end(), compare);
    // sort on the basis of first deadline then prefer job completion time

    bool flag = true;
    long long timer = 0; // timer starts from 0
    for (int i = 0; i < n; i++)
    {
        timer += v[i].first; // add the jobs completion time
        if (timer <= v[i].second) // if the timer is still less than equal to 
        // deadline we are safe
            continue;
        else // not safe now 
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

// TC - O(n + nlogn) ~ O(nlogn)
// SC - O(1)