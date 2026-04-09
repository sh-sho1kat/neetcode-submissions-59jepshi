class Solution {
public:
    set<vector<int>>v;
    void genperm(int n, vector<int>cur, vector<bool> check)
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
            
            if(!check[i])
            {
                cur.push_back(i);
                check[i] = true;
                genperm(n,cur,check);
                cur.pop_back();
                check[i] = false;
            }
        }
            
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        vector<int>cur;
        vector<bool> check(n,false);
        genperm(n,cur,check);
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
