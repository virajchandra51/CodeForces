#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, x;
    std::cin >> n >> x;
    
    if (x == 0) {
        if (n == 1) {
            std::cout << -1 << "\n";
        } else if (n % 2 == 0) {
            std::cout << n << "\n";
        } else {
            std::cout << n + 3 << "\n";
        }
        return;
    }
    if (x == 1) {
        if (n % 2 == 0) {
            std::cout << n + 3 << "\n";
        } else {
            std::cout << n << "\n";
        }
        return;
    }
    
    int ans = x;
    int p = __builtin_popcount(x);
    ans += (std::max(0, n - p) + 1) / 2 * 2;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}