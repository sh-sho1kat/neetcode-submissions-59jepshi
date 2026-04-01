class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> q;

        for(auto p:points)
        {
            pair<int,int> u = {p[0],p[1]};
            q.push({u.first*u.first + u.second*u.second,{u.first,u.second}});
            if(q.size()>k)
                q.pop();
        }
        vector<vector<int>> v;
        while(!q.empty())
        {
            // cout<<"ok"<<endl;
            pair<int,int> p = q.top().second;
            v.push_back({p.first, p.second});
            q.pop();
        }
        return v;

    }
};
