class Solution {
public:
    unordered_map<char,string>mp;
    vector<string> res;
    void func(int pos,string &digit, string s)
    {
        if(pos==digit.size())
        {
            res.push_back(s);
            return;
        }
        string  p = mp[digit[pos]];

        for(int i = 0;i<p.size();i++)
        {
            s.push_back(p[i]);
            func(pos+1,digit,s);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return res;
        mp['2']= "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string s;
        func(0,digits,s);
        return res;
    }
};
