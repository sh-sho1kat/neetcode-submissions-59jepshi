/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>>a;
        bool res =true;
        for(Interval interval:intervals)
        {
            a.push_back({interval.start,interval.end});
        }
        if(a.size()==0)
            return true;
        sort(a.begin(),a.end());
        int cur = a[0].second;
        for(int i = 1;i<a.size();i++)
        {
            if(a[i].first>=cur)
                cur = a[i].second;
            else
                res = false;
        }
        return res;
    }
};
