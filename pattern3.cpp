// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) // outer loop for rows
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if(i==1 || i==n)
//             {
//                 cout<<"*";
//             } // i stand at the first or last row
//             else
//             {
//                 if(j==1 || j==m)
//                 cout<<"*";
//                 else cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) // outer loop
    {
        for (int j = i; j <= n; j++) // inner loop
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}