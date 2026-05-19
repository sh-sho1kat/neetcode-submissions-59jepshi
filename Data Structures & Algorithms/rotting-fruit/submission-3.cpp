class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;

        int inf  = 100;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==0)
                    grid[i][j] = -1;
                if(grid[i][j] == 1)
                    grid[i][j] = inf;
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    grid[i][j] =0;
                }
            }
        }

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row+1<m and grid[row+1][col] != -1 and grid[row+1][col]>grid[row][col])
            {
                grid[row+1][col] = grid[row][col]+1;
                q.push({row+1,col});
            }
            if(row-1>=0 and grid[row-1][col] != -1 and grid[row-1][col]>grid[row][col])
            {
                grid[row-1][col] = grid[row][col]+1;
                q.push({row-1,col});
            } 

            if(col+1<n and grid[row][col+1] != -1 and grid[row][col+1]>grid[row][col])
            {
                grid[row][col+1] = grid[row][col]+1;
                q.push({row,col+1});
            }

            if(col-1>=0 and grid[row][col-1] != -1 and grid[row][col-1]>grid[row][col])
            {
                grid[row][col-1] = grid[row][col]+1;
                q.push({row,col-1});
            }
        }
        // for(int i = 0;i<m;i++)
        //     for(int j = 0;j<n;j++)
        //         cout<<grid[i][j]<<" ";

        int res =0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==inf)
                    return -1;
                if(grid[i][j]!=-1)
                    res = max(res,grid[i][j]);
                    
            }
        }
        return res;


        
    }
};
