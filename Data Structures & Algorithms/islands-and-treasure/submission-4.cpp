class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int m = grid.size();
        int n = grid[0].size();

        bool flag = true;
        for(int i =0;i<m;i++)
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                    flag = false;
                }
            }
        if(flag)
            return;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            int val = grid[row][col];

            q.pop();

            if(row+1<m)
            {
                if(grid[row+1][col]>val)
                {
                    grid[row+1][col] = val+1;
                    q.push({row+1,col});
                }
            }
            if(row-1>=0)
            {
                if(grid[row-1][col]>val)
                {
                    grid[row-1][col] = val+1;
                    q.push({row-1,col});
                }
            }
            if(col+1<n)
            {
                if(grid[row][col+1]>val)
                {
                    grid[row][col+1] = val+1;
                    q.push({row,col+1});
                }
            }
            if(col-1>=0)
            {
                if(grid[row][col-1]>val)
                {
                    grid[row][col-1] = val+1;
                    q.push({row,col-1});
                }
            }
        }
    }
};
