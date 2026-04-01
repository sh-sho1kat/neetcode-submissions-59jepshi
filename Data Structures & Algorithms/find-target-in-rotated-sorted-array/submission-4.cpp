class Solution {
public:

    int bs(int lo, int hi, vector<int>& nums,int target)
    {
        cout<<lo<<" "<<hi<<" "<<target<<endl;
        while(lo<=hi)
        {
            int mid = (lo+hi)>>1;
            cout<<mid<<" "<<nums[mid]<<" "<<target<<endl;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
            {
                hi = mid-1;
            }
            else
                lo = mid+1;
            
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0]<nums[n-1])
            return bs(0,n-1,nums,target);

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
        cout<<pos<<endl;
        int val1 = bs(0,pos-1,nums,target);
        int val2 = bs(pos,n-1,nums,target);

        cout<<val1<<" "<<val2<<endl;
        if(val1 != -1)
            return val1;
        else if(val2 != -1)
            return val2;
        else
            return -1;
    }
};
