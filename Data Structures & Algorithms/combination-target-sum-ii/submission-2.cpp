class Solution {
public:
    set<vector<int>> res;
    void func(vector<int> &nums,vector<int> &v,int pos, int sum, int target)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
            res.insert(v);
            return;
        }
        if(pos==nums.size())
            return;
        v.push_back(nums[pos]);
        func(nums,v,pos+1,sum+nums[pos],target);
        v.pop_back();

        while(pos+1<nums.size() and nums[pos] == nums[pos+1])
            pos++;
        func(nums,v,pos+1,sum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    vector<int>v;
    sort(nums.begin(),nums.end());
    func(nums,v,0,0,target);
    vector<vector<int>> ans;
    for(auto u:res)
        ans.push_back(u);    
    return ans;
    }
};
