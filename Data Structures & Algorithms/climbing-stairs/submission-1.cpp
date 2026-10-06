class Solution {
public:
    int dp[50];
    int numberofways(int cur, int n)
    {
        if(cur==n)
            return 1;
        if(cur>n)
            return 0;
        if(dp[cur]!=-1)
            return dp[cur];
        int ways = 0;
        ways = numberofways(cur+1,n)+ numberofways(cur+2,n);
        return dp[cur] = ways;
    }
    int climbStairs(int n) {
        for(int i = 0;i<=n;i++)
            dp[i]=-1;
        return numberofways(0,n);
    }
};
