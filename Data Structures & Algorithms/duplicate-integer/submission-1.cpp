class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto u:nums)
            {
                if(st.find(u)!=st.end())
                return true;
                st.insert(u);
            }
        return false;
    }
};