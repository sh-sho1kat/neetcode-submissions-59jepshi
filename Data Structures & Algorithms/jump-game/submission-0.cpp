class Solution {
public:
    bool canJump(vector<int>& a) {
        int cur =0;
        for(int i = 0;i<a.size();i++)
        {
            if(cur<i)
                return false;
            cur = max(cur, i+a[i]);
        }
        return true;
    }
};
