class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int colmn = matrix[0].size();
        int row = matrix.size();
        int lo = 0;
        int hi = row*colmn - 1;
        
        cout<<lo<<" "<<hi<<endl;

        while(lo <= hi)
        {
            int mid = (lo+hi) >> 1;
            int ro = mid/colmn;
            int col = mid%colmn;
            // cout<<ro<<" "<<col<<" "<<target<<endl;
            if(ro>=row or col>=colmn)
                break;
            if(matrix[ro][col] == target)
                return true;
            else if(matrix[ro][col] < target)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return false;
    }
};
