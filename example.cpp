class Solution
{
public:
    string findCommonResponse(vector<vector<string> > &responses)
    {
        unordered_map<string, int> m;
        for (auto res : responses)
        {
            unordered_set<string> s;
            for (auto i : res)
                s.insert(i);
            for (auto i : s)
                m[i]++;
        }
        int freq = -1;
        string ans;
        for (auto it : m)
        {
            if (it.second > freq)
            {
                freq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};