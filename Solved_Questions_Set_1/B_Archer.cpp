#include <bits/stdc++.h>
using namespace std;

// ans = p1 / (p1+p2-p1*p2) where p1 = a/b and p2 = c/d

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d; // taking input
    double numerator = a*d;
    double denominator = a*d+b*c-a*c;
    cout<<setprecision(12)<<(numerator/denominator)<<endl;
    return 0;
}

// time complexity - O(1)
// space complexity - O(1)