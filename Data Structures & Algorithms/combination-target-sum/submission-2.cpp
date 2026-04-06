class Solution {
public:
    vector<vector<int>> res;
    void func(vector<int> &nums,vector<int>v,int pos, int sum, int target)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
            res.push_back(v);
            return;
        }
        if(pos==nums.size())
            return;
        func(nums,v,pos+1,sum,target);
        v.push_back(nums[pos]);
        func(nums,v,pos,sum+nums[pos],target);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<int>v;
    func(nums,v,0,0,target);    
    return res;
    }
};
