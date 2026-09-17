class Solution {
public:
    int findkth(int k, vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        int lo = max(0,k-n);
        int hi = min(k,m);

        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            int taken_from_nums1 = mid;
            int taken_from_nums2 = k-mid;

            int mn = -1e9;
            int mx = 1e9;

            if(taken_from_nums1)
                mn = max(mn, nums1[taken_from_nums1-1]);

            if(taken_from_nums2)
                mn = max(mn, nums2[taken_from_nums2-1]);

            if(taken_from_nums1<m)
                mx = min(mx, nums1[taken_from_nums1]);

            if(taken_from_nums2<n)
                mx = min(mx, nums2[taken_from_nums2]);

            if(mn<=mx)
                return mn;
            
            if(taken_from_nums1 and taken_from_nums2<n and nums1[taken_from_nums1-1] > nums2[taken_from_nums2])
                hi = mid-1;
            else
                lo = mid+1;

        }
        return lo;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if((m+n)&1)
        {
            int val = findkth((m+n+1)/2, nums1, nums2);
            return val;
        }
        else
        {
            int val1 = findkth((m+n)/2,nums1,nums2);
            int val2 = findkth(((m+n)/2)+1,nums1,nums2);
            double res = (val1+val2)/2.0;
            return res;
        }
    }
};
