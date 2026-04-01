class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pre[n+5], post[n+5];
        int f = 1;
        for(int i = 0;i<n;i++)
        {
            f*=nums[i];
            pre[i] = f;
        }

        f =1;
        for(int i = n-1;i>=0;i--)
        {
            f*=nums[i];
            post[i] = f;
        }

        vector<int> v;
        for(int i =0; i<n;i++)
        {
            int res = 1;
            if(i)
                res *= pre[i-1];
            if(i<n-1)
                res *= post[i+1];
            v.push_back(res);
        }
        return v;
    }
};
