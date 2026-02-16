int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n + 1, 0);

    // Step 1: Build prefix sum array
    for (int i = 1; i <= n; i++)
    {
        int val = (nums[i - 1] == 1 ? 1 : -1);
        prefix[i] = prefix[i - 1] + val;
    }

    // Step 2: Use hashmap to find longest equal prefix values
    unordered_map<int, int> firstIndex;
    int maxLen = 0;

    for (int i = 0; i <= n; i++)
    {
        if (firstIndex.count(prefix[i]))
            maxLen = max(maxLen, i - firstIndex[prefix[i]]);
        else
            firstIndex[prefix[i]] = i;
    }

    return maxLen;
}

// Time Complexity: O(n)
// Space Complexity: O(n)