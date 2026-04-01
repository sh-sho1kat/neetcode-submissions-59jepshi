class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        int freq[105] = {};
        for (int i = 0; i < t.size(); i++)
            freq[t[i] - 'A']++;

        int mp[105] = {};
        int len = 1e9;
        int l = 0, r = 0;

        int n = s.size();

        while (r < n)
        {

            bool flag = true;
            for (int i = 0; i < 100; i++)
            {
                if (mp[i] < freq[i])
                    flag = false;
            }
            if (flag)
            {
                // cout << r << " " << l << endl;
                len = min(len, r - l);
                mp[s[l++] - 'A']--;
            }
            else
                mp[s[r++] - 'A']++;
        }
        // cout << len << endl;
        while (l < n)
        {
            bool flag = true;
            for (int i = 0; i < 100; i++)
            {
                if (mp[i] < freq[i])
                    flag = false;
            }
            if (flag)
                len = min(len, r - l);
            mp[s[l++] - 'A']--;
        }
        // cout << len << endl;
        if (len != 1e9)
        {
            l = 0;
            r = 0;
            int freq2[100] = {};
            while (r < len)
            {
                freq2[s[r++] - 'A']++;
            }
            while (r <= n)
            {
                // cout << l << " " << r << endl;
                bool f = true;
                for (int i = 0; i < 100; i++)
                {
                    if (freq[i] > freq2[i])
                        f = false;
                }
                if (f)
                {
                    // cout << "ok" << endl;
                    for (int pos = l; pos < r; pos++)
                        res.push_back(s[pos]);
                    break;
                }
                else
                {
                    freq2[s[l++] - 'A']--;
                    freq2[s[r++] - 'A']++;
                }
            }
        }
        return res;
         
    }
};
