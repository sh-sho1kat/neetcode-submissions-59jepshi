class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int>mp;
        int tmp = 1;
        for(auto u:strs)
        {
            string s = u;
            sort(s.begin(),s.end());
            if(!mp[s])
                mp[s]=tmp++;
        }
        vector<vector<string>> res(tmp-1);

        for(auto u:strs)
        {
            string s = u;
            sort(s.begin(),s.end());
            res[mp[s]-1].push_back(u);
        }
        return res;
    }
};
