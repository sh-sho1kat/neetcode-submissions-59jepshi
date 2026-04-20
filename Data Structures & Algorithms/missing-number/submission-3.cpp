class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int p=nums.size();
        for(int i=0;i<nums.size();i++)
            p^=i, p^=nums[i];
        return p;
    }
};
