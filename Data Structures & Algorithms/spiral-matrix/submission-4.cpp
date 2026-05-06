class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>res;

        bool left=1, right = 0, up = 0, down = 0;
        int i = 0, j =0;
        int inf = 10000;
        if(m==1)
        {
            for(int i = 0;i<n;i++)
                res.push_back(matrix[0][i]);
            return res;
        }

        if(n==1)
        {
            for(int i = 0;i<m;i++)
                res.push_back(matrix[i][0]);
            return res;
        }

        while(1)
        {
            if(matrix[i][j]==inf)
                return res;
            res.push_back(matrix[i][j]);
            matrix[i][j]=inf;

            if(left)
            {
                if(j+1==n or matrix[i][j+1]==inf)
                {
                    i++;
                    left = 0;
                    up =1;
                }
                else
                    j++;
            }
            else if(up)
            {
                if(i+1==m or matrix[i+1][j]==inf)
                {
                    j--;
                    up =0;
                    right = 1;
                }
                else
                    i++;
            }
            else if(right)
            {
                if(!j or matrix[i][j-1] == inf)
                {
                    i--;
                    right = 0;
                    down =1;
                }
                else
                    j--;
            }
            else if(down)
            {
                if(!i or matrix[i-1][j] == inf)
                {
                    j++;
                    down =0;
                    left =1;
                }
                else
                    i--;
            }

        }
    }
};
