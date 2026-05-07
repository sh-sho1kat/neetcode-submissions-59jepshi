class Solution {
public:
    bool isHappy(int n) {
        map<int,int>vis;

        while(!vis[n])
        {
            vis[n]=true;
            int p = 0;
            int tmp = n;
            while(tmp)
            {
                int digit = tmp%10;
                p+=digit*digit;
                tmp/=10;
            }
            if(p==1)
                return true;
            n = p;
        }
        return false;
    }
};
