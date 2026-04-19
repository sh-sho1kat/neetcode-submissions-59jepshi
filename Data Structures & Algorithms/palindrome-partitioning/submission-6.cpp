class Solution {
public:
    vector<vector<string>>res;
    bool dp[21][21]={};
    void func(int start, int pos, int n,string &s, vector<string> &v)
    {
        if(pos==n)
        {
            if(start==n-1)
                res.push_back(v);
            return;
        }
        func(start,pos+1,n,s,v);
        if(dp[start+1][pos])
        {
            v.push_back(s.substr(start+1,pos-start));
            func(pos,pos+1,n,s,v);
            v.pop_back();
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        for(int i = 0;i<s.size();i++)
            dp[i][i] = true;
        for(int i = s.size()-1;i>=0;i--)
        {
            for(int j = i;j<s.size();j++)
            {
                if(i+1==j)
                    dp[i][j] = (s[i]==s[j]);
                else if(i<j)
                {
                    dp[i][j] = dp[i+1][j-1] & (s[i]==s[j]);
                }
                
            }
        }
        for(int i = 0;i<s.size();i++)
        {
            for(int j = 0;j<s.size();j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<string>v;
        func(-1,0,s.size(),s,v);
        return res;
    }
};
