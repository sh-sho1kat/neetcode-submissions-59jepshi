class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i = 0;i<=n;i++)
        {
            int p = i;
            int ct=0;
            while(p)
            {
                if(p&1)
                    ct++;
                p/=2;
            }
            res.push_back(ct);
        }
        return res;
    }
};
