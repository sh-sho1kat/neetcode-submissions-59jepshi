class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int st = newInterval[0];
        int ed = newInterval[1];
        for(auto u:intervals)
        {
            vector<int> p = u;
            int ff = p[0];
            int ss = p[1];
            if(ss<st or ff>ed)
                res.push_back(p);
            else
            {
                if(ff<st)
                    st = ff;
                if(ss>=ed)
                    ed = ss;
            }
            
        }
        res.push_back({st,ed});

        sort(res.begin(),res.end());
        return res;

    }
};
