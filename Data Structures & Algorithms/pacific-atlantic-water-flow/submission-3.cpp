class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>pac(m,vector<int>(n,0)),atl(m,vector<int>(n,0));

        queue<pair<int,int>>q;

        for(int i = 0;i<n;i++)
            q.push({0,i}),pac[0][i] = 1;
        for(int i = 0 ;i<m;i++)
            q.push({i,0}),pac[i][0] = 1;

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            if(row-1>=0 and heights[row-1][col]>=heights[row][col] and !pac[row-1][col])
                q.push({row-1,col}),pac[row-1][col] = 1;

            if(row+1<m and heights[row+1][col]>=heights[row][col]and !pac[row+1][col])
                q.push({row+1,col}), pac[row+1][col] = 1;

            if(col-1>=0 and heights[row][col-1]>=heights[row][col]and !pac[row][col-1])
                q.push({row,col-1}), pac[row][col-1]= 1;

            if(col+1<n and heights[row][col+1]>=heights[row][col] and !pac[row][col+1])
                q.push({row,col+1}), pac[row][col+1]= 1;

        }

        for(int i = 0;i<n;i++)
            q.push({m-1,i}),atl[m-1][i] = 1;
        for(int i = 0 ;i<m;i++)
            q.push({i,n-1}),atl[i][n-1] = 1;

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            if(row-1>=0 and heights[row-1][col]>=heights[row][col] and !atl[row-1][col])
                q.push({row-1,col}),atl[row-1][col] = 1;

            if(row+1<m and heights[row+1][col]>=heights[row][col]and !atl[row+1][col])
                q.push({row+1,col}), atl[row+1][col] = 1;

            if(col-1>=0 and heights[row][col-1]>=heights[row][col]and !atl[row][col-1])
                q.push({row,col-1}), atl[row][col-1]= 1;

            if(col+1<n and heights[row][col+1]>=heights[row][col] and !atl[row][col+1])
                q.push({row,col+1}), atl[row][col+1]= 1;

        }

        vector<vector<int>>res;

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(pac[i][j] and atl[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }

        return res;


    }
};
