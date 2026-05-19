class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        int inf  = 10000;
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

            for(int i = row+1;i<m;i++)
            {
                if(grid[i][col]!=-1)
                {
                    if(grid[i][col]>grid[row][col])
                    {
                        grid[i][col] = grid[row][col]+1;
                        q.push({i,col});
                    }
                }
                break;
            }
            for(int i = row-1;i>=0;i--)
            {
                if(grid[i][col] != -1)
                {
                    if(grid[i][col]>grid[row][col])
                    {
                        grid[i][col] = grid[row][col]+1;
                        q.push({i,col});
                    }
                }
                break;
            }

            for(int i = col+1;i<n;i++)
            {
                if(grid[row][i]!=-1)
                {
                    if(grid[row][i]>grid[row][col])
                    {
                        grid[row][i] = grid[row][col]+1;
                        q.push({row,i});
                    }
                }
                break;
            }
            for(int i = col-1;i>=0;i--)
            {
                if(grid[row][i]!=-1)
                {
                    if(grid[row][i]>grid[row][col])
                    {
                        grid[row][i] = grid[row][col]+1;
                        q.push({row,i});
                    }
                }
                break;
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
