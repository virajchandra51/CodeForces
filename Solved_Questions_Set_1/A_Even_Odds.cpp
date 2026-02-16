#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long oddCount = (n + 1) / 2;

    if (k <= oddCount) {
        // k-th odd number
        cout << 2 * k - 1 << "\n";
    } else {
        // (k - oddCount)-th even number
        cout << 2 * (k - oddCount) << "\n";
    }
    return 0;
}
