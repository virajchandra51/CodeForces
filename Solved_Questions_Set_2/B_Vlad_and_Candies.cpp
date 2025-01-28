// Function to count occurrences of the target
int countOccurrences(const vector<int>& array, int target) {
    int first = lowerBound(array, target);
    if (first == -1) {
        return 0; // Target not found
    }
    int last = upperBound(array, target);
    return (last - first + 1); // Total occurrences
}
