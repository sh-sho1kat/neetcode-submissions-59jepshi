class TimeMap {
public:
    map<pair<string,int>,string>mp;
    unordered_map<string,set<int>>mp1;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[{key,timestamp}] = value;
        mp1[key].insert(-timestamp);
    }
    
    string get(string key, int timestamp) {
        // for(auto u:mp1[key])
        //     cout<<u<<" ";
        // cout<<endl;
        if(mp1[key].lower_bound(-timestamp)==mp1[key].end())
            return "";
        int time = *mp1[key].lower_bound(-timestamp);
        // cout<<time<<endl;
        return mp[{key,-time}];
    }
};
