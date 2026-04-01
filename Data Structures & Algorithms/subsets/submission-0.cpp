class Solution {
public:
    vector<vector<int>>res;
    void func(vector<int>& nums, vector<int>v, int pos)
    {
        if(pos==nums.size())
        {
            res.push_back(v);
            return;
        }
        func(nums,v,pos+1);
        v.push_back(nums[pos]);
        func(nums,v,pos+1);
        v.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        func(nums,v,0);
        return res;
    }
};
