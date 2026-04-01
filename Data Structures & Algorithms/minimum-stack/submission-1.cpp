class MinStack {
public:
    int st[1005];
    int cur = 0;
    int mn[1005];
    MinStack() {
        mn[0] = 9e9;
    }
    
    void push(int val) {
        cur++;
        st[cur] = val;
        mn[cur] = min(mn[cur-1],val);
    }
    
    void pop() {
        if(cur)
            cur--;
    }
    
    int top() {
        if(cur)
            return st[cur];
    }
    
    int getMin() {
        if(cur)
            return mn[cur];
    }
};
