class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        map<int,int> mp;
        for(auto u:a)
            mp[u]++;
        int n = a.size();
        set<vector<int>> res;
        for(int i = 0;i<n;i++)
        {
            mp[a[i]]--;
            for(int j = i+1;j<n; j++)
            {
                mp[a[j]]--;
                int tmp = -a[i]-a[j];
                int cur = mp[tmp];
                if(cur)
                {
                    
                    for(int k =0;k<cur;k++)
                    {
                        vector<int> v;
                        v.push_back(a[i]);
                        v.push_back(a[j]);
                        v.push_back(tmp);

                        sort(v.begin(), v.end());
                        res.insert(v);
                    }
                    
                }
            }
            for(int j = i+1;j<n; j++)
            {
                mp[a[j]]++;
            }
        }
        vector<vector<int>> ans;
        for (auto u:res)
        {
            ans.push_back(u);
        }
        return ans;
    }
};
