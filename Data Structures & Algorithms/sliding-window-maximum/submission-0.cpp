class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        int l = 0;
        multiset<int> st;
        for (int r = 0; r < k - 1; r++)
            st.insert(nums[r]);
            
        for (int r = k - 1; r < n; r++)
        {
            st.insert(nums[r]);
            res.push_back(*st.rbegin());
            st.erase(st.lower_bound(nums[l++]));
        }
        return res;

    }
};
