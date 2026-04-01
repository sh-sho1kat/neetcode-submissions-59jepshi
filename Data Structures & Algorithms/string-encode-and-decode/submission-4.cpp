class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto u:strs)
            s+=u,s+="#shoikat#";
        s+="#shoikat#";
        return s;
    }

    vector<string> decode(string s) {
        vector<string>v;
        string tmp;
        for(int i =0; i<s.size()-9;i++)
        {
            if(s[i] == '#' and s[i+1]=='s' and s[i+2]=='h' and s[i+3]=='o' and s[i+4]=='i' and s[i+5]=='k' and s[i+6]=='a' and s[i+7]=='t' and s[i+8]=='#')
            {
                v.push_back(tmp);
                tmp.clear();
                i+=8;
            }
            else
                tmp.push_back(s[i]);
        }
        return v;
    }
};
