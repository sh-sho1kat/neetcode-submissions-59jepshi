class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;

        for(auto u:nums)
        {
            q.push(-u);
            if(q.size()>k)
                q.pop();
            // cout<<q.top()<<" ";
        }

        // while(q.size()>1)
        // {
        //     // cout<<q.top()<<" ";
        //     q.pop();
        // }
        return -q.top();
    }
};
