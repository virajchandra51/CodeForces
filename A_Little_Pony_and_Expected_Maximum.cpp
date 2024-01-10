#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n, m;
    cin >> n >> m;
    double answer = n;
    for (double i = n - 1; i >= 1; i--)
    {
        double sub = pow(i / n, m);
        answer -= sub;
    }
    cout << setprecision(12) << answer << endl;
    return 0;
}