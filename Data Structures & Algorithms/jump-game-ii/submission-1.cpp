class Solution {
public:
    int jump(vector<int>& a) {
        if(a.size()==1)
            return 0;
        for(int i = 0;i<a.size();i++)
        {
            a[i]+=i;
        }
        for(int i =0;i<a.size();i++)
        {
            cout<<a[i]<<"  ";
        }
        cout<<endl;
        int cur = a[0];
        int idx = 0;
        int cnt = 1;

        while(cur<a.size()-1)
        {
            cout<<idx<<" "<<cur<<endl;
            int mx = 0;
            int ix =0;
            for(int i = idx;i<=cur;i++)
            {
                if(a[i]>=mx)
                {
                    mx = a[i];
                    ix = i;
                }
            }
            cur = mx;
            idx = ix;
            cnt++;

        }
        return cnt;
    }
};
