class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>> q;

        int m = grid.size();
        int n = grid[0].size();

        bool flag = true;
        for(int i =0;i<m;i++)
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({-grid[i][j],{i,j}});
                    flag = false;
                }
            }
        if(flag)
            return;
        
        while(!q.empty())
        {
            int val = -q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;

            q.pop();

            if(row+1<m)
            {
                if(grid[row+1][col]>val)
                {
                    grid[row+1][col] = val+1;
                    q.push({-grid[row+1][col],{row+1,col}});
                }
            }
            if(row-1>=0)
            {
                if(grid[row-1][col]>val)
                {
                    grid[row-1][col] = val+1;
                    q.push({-grid[row-1][col],{row-1,col}});
                }
            }
            if(col+1<n)
            {
                if(grid[row][col+1]>val)
                {
                    grid[row][col+1] = val+1;
                    q.push({-grid[row][col+1],{row,col+1}});
                }
            }
            if(col-1>=0)
            {
                if(grid[row][col-1]>val)
                {
                    grid[row][col-1] = val+1;
                    q.push({-grid[row][col-1],{row,col-1}});
                }
            }
        }
    }
};
