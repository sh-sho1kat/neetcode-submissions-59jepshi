class Solution {
public:
    vector<vector<string>>res;

    bool check_palindrome(int start, int end, string &s)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void func( int pos, int n,string &s, vector<int>v)
    {
        if(pos==n)
        {
            v.push_back(pos);
            vector<string>p;
            for(int i = 1;i<v.size();i++)
            {
                if(check_palindrome(v[i-1],v[i]-1,s))
                {
                    p.push_back(s.substr(v[i-1],v[i]-v[i-1]));
                }
                else
                    return;
            }
            res.push_back(p);
            return;
        }
        func(pos+1,n,s,v);
        v.push_back(pos);
        func(pos+1,n,s,v);
        v.pop_back();
        return;

    }
    vector<vector<string>> partition(string s) {
        vector<int>v;
        v.push_back(0);
        func(1,s.size(),s,v);
        return res;
    }
};
