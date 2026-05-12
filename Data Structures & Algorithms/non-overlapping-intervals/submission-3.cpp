class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());


        int inf = -500000;
        int ed = inf;
        int cured = 0;
        int cnt =0;

        for(int i = 0;i<intervals.size();i++)
        {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            cured = intervals[i][1];
            if(ed==inf)
            {
                
                ed = cured;
            }
            else
            {
                if(intervals[i][0]>=ed)
                    ed = cured;
                else
                {
                    cnt++;
                    ed = min(ed,cured);
                }
            }
        }
        return cnt;
    }
};
