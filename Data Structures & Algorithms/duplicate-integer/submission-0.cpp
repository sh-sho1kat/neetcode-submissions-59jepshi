class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto u:nums)
            st.insert(u);
        
        if(nums.size()==st.size())
        return false;
        return true;
    }
};