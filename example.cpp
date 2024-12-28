#include <iostream>
using namespace std;

int main() {
    int n = 5, m = 3;
    // Outer loop runs 'n' times
    for (int i = 0; i < n; i++) {
        // Inner loop runs 'm' times for each iteration of the outer loop
        for (int j = 0; j < m; j++) {
            cout << "* ";
        }
        cout << "\n";
    }

    return 0;
}
