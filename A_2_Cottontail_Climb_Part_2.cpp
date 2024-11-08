#include <iostream>
using namespace std;

// Function to count valid combinations based on the given digit X and positions y
long long countValidCombinations(int X, int y) {
    if (X <= 1 || y <= 0) return 0; // No valid digits less than X or positions

    // For y = 1, simply return the count of valid digits
    if (y == 1) {
        return X - 1; // Valid digits are {1, 2, ..., X-1}
    }

    long long totalCombinations = 0;

    // Iterate through possible first digits for the left positions (1 to X-1)
    for (int firstDigit = 1; firstDigit < X; ++firstDigit) {
        // For y positions in non-decreasing and non-increasing order,
        // we can fill them directly as valid digits are less than X
        long long leftCount = 1;  // We are choosing only one digit
        long long rightCount = 1; // Same for the right side

        // Total combinations for this firstDigit
        totalCombinations += leftCount * rightCount;
    }

    return totalCombinations; // Total combinations
}

int main() {
    int X, y;
    cout << "Enter digit X: ";
    cin >> X;
    cout << "Enter number of positions y: ";
    cin >> y;

    long long result = countValidCombinations(X, y);
    cout << "Total valid combinations: " << result << endl;

    return 0;
}
