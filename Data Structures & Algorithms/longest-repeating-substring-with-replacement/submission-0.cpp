class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int n = s.size();
        int freq[30]={};
        int l = 0;
        int r = 0;

        while(r<n)
        {
            int mx =0;
            int tot =0;
            for(int i = 0;i<26;i++)
                mx = max(mx, freq[i]),tot += freq[i];

            int tmp = tot-mx;
            if(tmp>k)
                freq[s[l++]-'A']--;
            else
                {
                    freq[s[r++]-'A']++;
                    res = max(res,tot);
                }
        }
        while(l<n)
        {
            int mx =0;
            int tot =0;
            for(int i = 0;i<26;i++)
                mx = max(mx, freq[i]),tot += freq[i];

            int tmp = tot-mx;
            if(tmp<=k)
                res = max(res,tot);

            freq[s[l++]-'A']--;
        }
        return res;
    }
};















