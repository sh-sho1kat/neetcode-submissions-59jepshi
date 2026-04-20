class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        bitset<1005>st;
        for(int i=0;i<nums.size();i++)
            st.set(nums[i]);
        for(int i = 0;i<=n;i++)
            if(!st[i])
                return i;

    }
};
