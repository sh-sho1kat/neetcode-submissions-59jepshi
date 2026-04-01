class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int a[30]={};
        for(int i = 0;i<tasks.size();i++)
            a[tasks[i]-'A']++;
        priority_queue<int>q;

       for(int i = 0;i<26;i++)
            if(a[i])
                q.push(a[i]);

        int res = 0;
        int cur = n;
        while(!q.empty())
        {
            cur = 0;
            vector<int>v;
            while(!q.empty())
            {
                int p = q.top();
                q.pop();
                p--;
                if(p)
                    v.push_back(p);
                cur++;
                if(cur==n)
                    break;
            }
            if(q.empty() and v.size())
                res++,res+=n;
            else
                res+=cur;
            for(auto u:v)
                q.push(u);
        }
        return res;
    }
};
