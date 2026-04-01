class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map <char, int> mp;
        int l = 0;
        int mx = 0;
        for(int i = 0;i<n;i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>1)
            {
                while(mp[s[i]]>1)
                {
                    mp[s[l++]]--;
                }
            }
            mx = max(mx, i - l + 1);
        }
        return mx;
    }
};
