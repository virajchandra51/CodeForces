#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<long long> > a(n, vector<long long>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j]; // taking input
        }

        long long answer = 0;

        for (int i = 0; i < m; i++)
        {
            vector<long long> columnElements; // to store the elements in a column
            for (int j = 0; j < n; j++)
                columnElements.push_back(a[j][i]);

            sort(columnElements.begin(), columnElements.end());
            reverse(columnElements.begin(), columnElements.end());
            // dec sort the array

            long long sum = 0;
            for (auto it : columnElements)
                sum += it;
            // taking sum of the array

            for (int k = 0; k < columnElements.size(); k++)
            {
                long long takeTimes = (columnElements.size() - k);
                // finding how many times do I take this element bigger than all
                answer += ((takeTimes * columnElements[k]) - sum);
                // add the net absolute sum it can create with elements coming after it
                sum -= columnElements[k]; 
                // substract the currect total sum of array with this value and move on to next
            }
        }

        cout << answer << endl;
        
    }
    return 0;
}

// TC - O(m*nlogn)
// SC - O(n)