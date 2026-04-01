class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int mx = 0;
        int res = 0;
        int tmp =0;
        for(int i = n -1;i>=0;i--)
        {
            if(a[i]>=mx)
            {
                tmp = 0;
                mx = a[i];
            }
            tmp = mx-a[i];
            res = max(res,tmp);
        }
        return res;
    }
};
