class Solution {
public:
    bool isPalindrome(string s) {
        string p;
        for(int i =0; i<s.size(); i++)
        {
            if((s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9'))
                p.push_back(s[i]);
            else if(s[i] >= 'A' and s[i] <= 'Z')
                p.push_back(tolower(s[i]));
        }

        int l =0, r = p.size()-1;

        while(l<r)
        {
            if(p[l]!=p[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
