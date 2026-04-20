class Solution {
public:
    int dp[105][105];
    bool func(int pos, int val,string &s)
    {
        if(!val)
            return false;
        if(pos==s.size())
        {
            if(val==1)
                return true;
            return false;
        }
        if(dp[pos][val]!=-1)
            return dp[pos][val];
        bool ans = false;
        if(s[pos]=='(')
            ans |= func(pos+1,val+1,s);
        if(s[pos]==')')
            ans |= func(pos+1,val-1,s);
        if(s[pos]=='*')
        {
            ans |= func(pos+1,val-1,s);
            ans |= func(pos+1,val+1,s);
            ans |= func(pos+1,val,s);
        }
        return dp[pos][val] = ans;

    }
    bool checkValidString(string s) {
        for(int i = 0;i<=s.size();i++)
        {
            for(int j = 0;j<=s.size();j++)
            {
                dp[i][j] = -1;
            }
        }
        bool ans = func(0,1,s);
        return ans;
    }
};
