class Solution {
public:
    int dp[105][105];
    int func(int pos1, int pos2, int m, int n, string &w1, string &w2)
    {
        if(pos2==n)
        {
            return m-pos1;
        }
        if(pos1==m)
        {
            return n-pos2;
        }
        if(dp[pos1][pos2]!=-1)
            return dp[pos1][pos2];
        int res = 1<<30;
        if(w1[pos1]==w2[pos2])
            res = func(pos1+1,pos2+1,m,n,w1,w2);
        int res1 = func(pos1+1,pos2+1,m,n,w1,w2)+1;
        int res2 = func(pos1,pos2+1,m,n,w1,w2)+1;
        int res3 = func(pos1+1,pos2,m,n,w1,w2)+1;

        res = min({res1,res2,res3,res});

        return dp[pos1][pos2] = res;
        

    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        for(int i=0;i<=m;i++)
            for(int j = 0;j<=n;j++)
                dp[i][j] = -1;

        int res = func(0,0,m,n,word1,word2);

        return res;
    }
};
