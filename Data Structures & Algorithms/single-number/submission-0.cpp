class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val =0;
        for(auto u:nums)
            val^=u;
        return val;
    }
};
