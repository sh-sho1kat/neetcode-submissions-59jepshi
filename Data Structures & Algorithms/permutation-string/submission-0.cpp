class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool flag = false;

        int freq1[30]={};
        int freq2[30] = {};

        for(int i = 0; i<s1.size();i++)
            freq1[s1[i]-'a']++;

        int l = 0;
        int r = 0;
        int n = s2.size();
        while(r<n)
        {
            freq2[s2[r++]-'a']++;
            bool f = false;
            for(int i = 0;i<26;i++)
                if(freq2[i]>freq1[i])
                    f = true;
            while(f)
            {
                freq2[s2[l++]-'a']--;
                f = false;
                for(int i = 0;i<26;i++)
                    if(freq2[i]>freq1[i])
                        f = true;
            }
            bool fun = true;
            for(int i = 0 ;i<26;i++)
            {
                if(freq1[i]!=freq2[i])
                    fun = false;
            }
            if(fun)
                return true;
        }
        return false;
    }
};
