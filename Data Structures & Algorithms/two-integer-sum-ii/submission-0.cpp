class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0 ; i < n ; i++)
        {
            int l = i+1;
            int r = n-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(numbers[mid]+numbers[i]==target)
                {
                    vector<int>v;
                    v.push_back(i+1);
                    v.push_back(mid+1);
                    return v;
                }
                else if(numbers[mid]+numbers[i] > target)
                    r = mid-1;
                else
                    l = mid+1;
            }
        }
    }
};
