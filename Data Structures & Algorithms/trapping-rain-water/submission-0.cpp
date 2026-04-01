class Solution {
public:
    int trap(vector<int>& a) {
        int res =0;

        int n = a.size();

        int mxa[n+5]={};
        int mx = 0;
        for(int i =n-1;i>=0;i--)
        {
            mxa[i] = mx;
            mx = max(mx,a[i]);
        }

        mx = 0; 

        for(int i =0;i<n;i++)
        {
            if(mx>=a[i] and mxa[i]>=a[i])
                res+=min(mx,mxa[i])-a[i];
            mx = max(mx,a[i]);
        }

        return res;
    }
};
