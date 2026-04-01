class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1;
        long long hi = 1e18;
        long long res = hi;
        while(lo<=hi)
        {
            long long mid = (lo+hi)/2;
            long long hour = 0;
            for(auto u:piles)
            {
                hour  += u/mid;
                if(u%mid)
                    hour++;
            }
            if(hour<=h)
            {
                res = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return res;
    }
};
