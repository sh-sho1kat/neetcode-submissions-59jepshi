class Solution {
public:
    set<vector<int>>v;
    void genperm(int n, vector<int>cur)
    {
        if(cur.size()==n)
        {
            // for(auto u:cur)
            // cout<<u<<" ";
            v.insert(cur);
            return;
        }
        for(int i = 0;i<n;i++)
        {
            bool f = true;
            for(int j = 0;j<cur.size();j++)
            {
                if(cur[j]==i)
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                cur.push_back(i);
                genperm(n,cur);
                cur.pop_back();
            }
        }
            
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        vector<int>st;
        genperm(n,st);
        for(auto u:v)
        {
            vector<int>tmp;
            for(auto uu:u)
            {
                tmp.push_back(nums[uu]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
