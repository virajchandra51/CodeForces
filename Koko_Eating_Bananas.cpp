class Solution {
public:
    bool checker(int mid, vector<int> &piles, int h)
    {
        long long hours = 0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=(ceil(piles[i]*1.0/mid));
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<piles.size();i++) high=max(high,piles[i]);
        int ans;
        while(low<=high) // O(log2(ss))
        {
            int mid = (low+high)/2;
            if(checker(mid,piles,h)) // O(n)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

// tc - O(n*log2(SS)) = O(10^4*30) = (3*10^5) ~ 10^5
// sc - O(n)