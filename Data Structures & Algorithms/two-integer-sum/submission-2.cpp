class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(auto u:nums)
            mp[u]++;

        int idx = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int req = target-nums[i];
            if(mp[req]>1 or (mp[req]==1 and nums[i]*2!=target))
            {
                idx = i;
                break;
            }
        }
        vector<int> p;
        p = {idx};
        for(int i = idx+1;i<nums.size();i++)
        {
            if((nums[i]+nums[idx])==target)
            {
                p.push_back(i);
                return p;
            }
        }
    }
};
