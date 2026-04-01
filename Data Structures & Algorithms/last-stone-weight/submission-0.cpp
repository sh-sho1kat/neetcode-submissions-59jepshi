class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;

        for(auto u:stones)
            q.push(u);
        while(q.size()>1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            a-=b;
            q.push(a);
        }
        return q.top();
    }
};
