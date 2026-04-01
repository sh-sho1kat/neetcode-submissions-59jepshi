class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int left[n+5]={};
        int right[n+5]={};
        stack<pair<int,int>>st;
        st.push({-1,n});
        for(int i = n-1;i>=0;i--)
        {
            while(!st.empty())
            {
                int val = st.top().first;
                if(heights[i]<=val)
                    st.pop();
                else
                {
                    right[i]=st.top().second;
                    st.push({heights[i],i});
                    break;
                }

            }
        }
        while(!st.empty())
        {
            st.pop();
        }

        st.push({-1,-1});
        for(int i = 0;i<n;i++)
        {
            while(!st.empty())
            {
                int val = st.top().first;
                if(heights[i]<=val)
                    st.pop();
                else
                {
                    left[i]=st.top().second;
                    st.push({heights[i],i});
                    break;
                }

            }
        }

        int res = 0;
        for(int i = 0 ;i<n; i++)
        {
            // cout<<heights[i]<<" "<<right[i]-left[i]<<endl;
            res = max(res,heights[i]*(right[i]-left[i]-1));
        }
        return res;
    }
};
 