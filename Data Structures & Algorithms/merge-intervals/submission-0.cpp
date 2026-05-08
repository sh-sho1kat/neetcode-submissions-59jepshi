class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        for(vector<int>u:intervals)
        {
            if(!res.size())
                res.push_back(u);
            else
            {
                if(res[res.size()-1][0]==u[0] and res[res.size()-1][1]<=u[1])
                    res[res.size()-1][1] = u[1];
                else if(res[res.size()-1][1]>=u[0] and res[res.size()-1][1]<=u[1])
                    res[res.size()-1][1] = u[1];
                else if(res[res.size()-1][1]<u[0])
                    res.push_back(u);
            }
        }
        return res;
    }
};
