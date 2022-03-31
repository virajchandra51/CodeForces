#include <bits/stdc++.h>
using namespace std;
#define fast \
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define pb push_back
#define len length
#define sub substr
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define B(x) (1 << x)

int main() {
    fast int t, l;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        l = s.len();
        sort(s.begin(), s.begin() + l / 2);
        if (s.len() % 2 == 0) {
            sort(s.begin() + l / 2, s.end());
            /*cout << */(s.sub(0, l / 2) == s.sub(l / 2, l / 2) ?cout<< "yes\n" :cout<< "no\n");
        } else {
            sort(s.begin() + l / 2 + 1, s.end());
            /*cout << */(s.sub(0, l / 2) == s.sub(l / 2 + 1, l / 2) ?cout<< "yes\n" :cout<< "no\n");
        }
        s.clear();
    }
}