class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if(nums[n-1]>nums[0])
            return nums[0];

        int lo = 1, hi = n-1;
        int pos = 0;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;

            if(nums[0]>nums[mid])
            {
                pos = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return nums[pos];
    }
};
