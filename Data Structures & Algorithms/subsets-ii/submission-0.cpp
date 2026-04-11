class Solution {
public:
    set<vector<int>> res;
    void func(int pos, vector<int>&nums, vector<int>cur)
    {
        if(pos==nums.size())
        {
            res.insert(cur);
            return;
        }
        func(pos+1,nums,cur);
        cur.push_back(nums[pos]);
        func(pos+1,nums,cur);
        cur.pop_back();
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        func(0,nums,v);
        vector<vector<int>> ans;
        for(auto u:res)
        {
            ans.push_back(u);
        }
        return ans;
    }
};
