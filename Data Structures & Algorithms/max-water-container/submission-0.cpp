class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mxarea =0;

        int n = heights.size();
        int l = 0, r = n -1; 
        while(l<r)
        {
            int cur = min(heights[l], heights[r])*(r-l);
            mxarea = max(mxarea, cur);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return mxarea;
    }
};
