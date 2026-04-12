class Solution {
public:
    vector<string> res;

    void generate(string s,int left,int right)
    {
        if(!left and !right)
        {
            res.push_back(s);
            return;
        }
        if(right>left)
            generate(s+")",left,right-1);
        if(left)
            generate(s+"(",left-1,right);
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        return res;
    }
};
