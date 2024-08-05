#include <bits/stdc++.h>

using namespace std;

int ask(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int main()
{
    vector<int> p = {4, 8, 15, 16, 23, 42}; // 6
    map<int, pair<int, int> > mp; // 36
    for (int i = 0; i < 6; i++) // n
    {
        for (int j = i + 1; j < 6; j++) // n
        {
            mp[p[i] * p[j]] = {p[i], p[j]}; // logn
        }
    } // n^2 * logn = 36 * 3 = 108 ~ 100
    int ab = ask(1, 2);
    int ac = ask(1, 3);
    int ad = ask(1, 4);
    int ae = ask(1, 5);
    
    int a;
    if(mp[ab].first == mp[ac].first || mp[ab].first == mp[ac].second)
        a = mp[ab].first;
    else
        a = mp[ab].second;
    
    int b = ab / a;
    int c = ac / a;
    int d = ad / a;
    int e = ae / a;

    p.erase(find(p.begin(), p.end(), a));
    p.erase(find(p.begin(), p.end(), b));
    p.erase(find(p.begin(), p.end(), c));
    p.erase(find(p.begin(), p.end(), d));
    p.erase(find(p.begin(), p.end(), e));

    cout<<"! "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<p[0]<<endl;

    return 0;
}

// tc - O(100)
// sc - O(36)