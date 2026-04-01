class KthLargest {
public:
    priority_queue<int>q;
    int p;
    KthLargest(int k, vector<int>& nums) {
        p = k;
        for(auto u:nums)
            q.push(-u);
        while(q.size()>k)
            q.pop();
        
    }
    
    int add(int val) {
        q.push(-val);
        if(q.size()>p)
            q.pop();
        return -q.top();
    }
};
