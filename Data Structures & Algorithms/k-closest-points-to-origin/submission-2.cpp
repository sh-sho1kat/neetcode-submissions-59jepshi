class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> q;

        for(auto p:points)
        {
            pair<int,int> u = {p[0],p[1]};
            q.push({p[0]*p[0] + p[1]*p[1], {p[0], p[1]}});
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
