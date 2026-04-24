class Solution {
public:
    void dfs(int row,int col, vector<vector<char>>& grid)
    {
        // cout<<row<<" "<<col<<endl;
        if(row<0 or row>=grid.size() or col<0 or col>=grid[0].size())
            return;
        if(grid[row][col]=='0')
            return;
        grid[row][col]='0';
        dfs(row+1,col,grid);
        dfs(row,col+1,grid);
        dfs(row-1,col,grid);
        dfs(row,col-1,grid);

        return;


    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int res =0;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    res++;
                }
            }
        }
        return res;
    }
};




