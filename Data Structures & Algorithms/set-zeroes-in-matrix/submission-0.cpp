class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        
        vector<bool> ar1(n+5, false);
        vector<bool> ar2(m+5, false);

        for(int i = 0;i<m;i++)
        {
            bool flag = false;
            for(int j = 0;j<n;j++)
                if(!matrix[i][j])
                    flag = true;
            if(flag)
            ar2[i]=1;
        }

        for(int i = 0;i<n;i++)
        {
            bool flag = false;
            for(int j = 0;j<m;j++)
                if(!matrix[j][i])
                    flag = true;
            if(flag)
            ar1[i]=1;
        }

        for(int i =0;i<m;i++)
        {
            if(ar2[i])
            {
                for(int j = 0;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
            
        }
        for(int i =0;i<n;i++)
        {
            if(ar1[i])
            {
                for(int j = 0;j<m;j++)
                {
                    matrix[j][i]=0;
                }
            }
            
        }
    }
};
