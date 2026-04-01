class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int,int>> st;
        vector<int>res;
        st.push({1000,n});
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty())
            {
                if(t[i]>=st.top().first)
                    st.pop();
                else
                {
                    if(st.top().first==1000)
                        res.push_back(0);
                    else
                        res.push_back(st.top().second-i);
                    st.push({t[i],i});
                    break;
                }
            }
        }
       reverse(res.begin(),res.end());
       return res;

    }
};
