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
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cout << "*";
    cout << endl; // first row

    // mid code
    for (int i = 1; i <= n - 2; i++)
    {
        cout << "*";
        for (int j = 1; j <= m - 2; j++)
            cout << " ";
        
        cout << "*";

        cout << endl;
    }

    for (int i = 1; i <= m; i++)
        cout << "*";
    cout << endl; // last row
    return 0;
}