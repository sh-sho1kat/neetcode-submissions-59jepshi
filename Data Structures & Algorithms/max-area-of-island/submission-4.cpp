class Solution {
public:
    int dfs(int row,int col, vector<vector<int>>& grid)
    {
        // cout<<row<<" "<<col<<endl;
        if(row<0 or row>=grid.size() or col<0 or col>=grid[0].size())
            return 0;
        if(!grid[row][col])
            return 0;
        grid[row][col]=0;
        int res = 1;
        res += dfs(row+1,col,grid);
        res += dfs(row,col+1,grid);
        res += dfs(row-1,col,grid);
        res += dfs(row,col-1,grid);

        return res;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int res =0;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    res = max(res, dfs(i,j,grid));
                }
            }
        }
        return res;
    }
};
