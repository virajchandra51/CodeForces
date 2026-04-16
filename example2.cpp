int main()
{
    vector<pair<long long, long long> > queries = {
        {50, 500},
        {500, 1000},
        {50, 1000}};

    // ---------------------------------------
    // STEP 1: Collect Important Points
    // ---------------------------------------

    set<long long> st;
    for (auto q : queries)
    {
        st.insert(q.first);
        st.insert(q.second + 1);
    }

    // ---------------------------------------
    // STEP 2: Assign Compressed Indices
    // ---------------------------------------
    map<long long, int> mp;
    int rank = 0;
    for (auto x : st)
    {
        mp[x] = rank;
        rank++;
    }

    return 0;
}