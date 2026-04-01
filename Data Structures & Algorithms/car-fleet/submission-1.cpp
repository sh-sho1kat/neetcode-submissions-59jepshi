class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        for(int i = 0 ;i<position.size();i++)
            v.push_back({position[i],speed[i]});
        
        sort(v.begin(),v.end());
        double mxtm = 0.0;
        int cnt = 0;
        for(int i = v.size()-1;i>=0;i--)
        {
            double req = (target-v[i].first)/(v[i].second*1.0);
            cout<<mxtm<<" "<<req<<endl;
            if(req>mxtm)
            {
                cnt++;
                mxtm = req;
            }

        }
        return cnt;
    }
};
