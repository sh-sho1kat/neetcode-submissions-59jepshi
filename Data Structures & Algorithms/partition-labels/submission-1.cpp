class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int>res;
        int ct =0;
        int last = 0;
        map<char,int>mp;
        for(int i = 0;i<n;i++)
            mp[s[i]]=i;
        for(int i = 0;i<n;i++)
        {
            int lc = mp[s[i]];
            if(lc>last)
                last = lc;
            ct++;
            if(last==i)
            {
                res.push_back(ct);
                ct = 0;
            }
        }
        return res;
    }
};
