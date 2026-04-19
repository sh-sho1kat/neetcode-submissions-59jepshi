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
    void func(int start, int pos, int n,string &s, vector<string>v)
    {
        if(pos==n)
        {
            if(start==n-1)
                res.push_back(v);
            return;
        }
        func(start,pos+1,n,s,v);
        if(check_palindrome(start+1,pos,s))
        {
            v.push_back(s.substr(start+1,pos-start));
            func(pos,pos+1,n,s,v);
            v.pop_back();
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        func(-1,0,s.size(),s,v);
        return res;
    }
};
