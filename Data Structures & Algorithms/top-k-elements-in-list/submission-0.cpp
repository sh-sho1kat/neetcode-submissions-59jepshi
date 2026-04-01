class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto u:nums)
            mp[u]++;

        set<pair<int,int>>st;

        for(auto u:mp)
            st.insert({-u.second,u.first});

        vector<int>v;
        for(auto u:st)
        {
            if(k--)
                v.push_back(u.second);
            else
                break;
        }
        return v;
    }
};
