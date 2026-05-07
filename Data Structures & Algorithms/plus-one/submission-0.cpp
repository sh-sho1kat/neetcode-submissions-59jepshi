class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int rem =1;
        for(int  i =digits.size()-1;i>=0;i--)
        {
            int sum = rem+digits[i];
            res.push_back(sum%10);
            rem = sum/10;
        }
        if(rem)
            res.push_back(rem);
        reverse(res.begin(),res.end());
        return res;
    }
};
