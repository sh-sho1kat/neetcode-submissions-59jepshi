class LRUCache {
public:
    unordered_map<int,int> mp,mp1;
    queue<int>q;
    int sz;
    int cursz;
    LRUCache(int capacity) {
        sz = capacity;
        cursz = 0;
    }
    
    int get(int key) {
        int val;
        if(mp.find(key)==mp.end() or mp[key] == -1)
            return -1;
        cout<<"ok"<<endl;
        q.push(key);
        mp1[key]++;
        return mp[key];
    }
    
    void put(int key, int value) {

        if(mp.find(key)==mp.end() or mp[key]==-1)
            cursz++;
        mp[key] = value;
        q.push(key);
        mp1[key]++;
        while(cursz>sz)
        {
            int p = q.front();
            q.pop();
            mp1[p]--;
            if(!mp1[p])
            {
                mp[p]=-1;
                cursz--;
            }
        }
        return;
    }
};
