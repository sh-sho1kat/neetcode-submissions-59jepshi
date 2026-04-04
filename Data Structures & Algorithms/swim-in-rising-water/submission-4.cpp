class Solution {
public:
    bool func(vector<vector<int>>v,int val)
    {
        int n = v.size();
        bool vis[n+5][n+5]={};

        queue<pair<int,int>>q;
        q.push({0,0});
        if(v[0][0]>val)
            return false;
        vis[0][0] = true;
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            int i = p.first, j = p.second;
            if(i == n-1 and j == n-1)
                return true;
            q.pop();
            if(i+1<n and v[i+1][j]<=val and !vis[i+1][j])
            {
                q.push({i+1,j});
                vis[i+1][j] = true;
            }
            if(i-1>=0 and v[i-1][j]<=val and !vis[i-1][j])
            {
                q.push({i-1,j});
                vis[i-1][j] = true;
            }
            if(j+1<n and v[i][j+1]<=val and !vis[i][j+1])
            {
                q.push({i,j+1});
                vis[i][j+1] = true;
            }    
            if(j-1>=0 and v[i][j-1]<=val and !vis[i][j-1])
            {
                q.push({i,j-1});
                vis[i][j-1] = true;
            }


        }
        return false;


    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int lo = 0, hi = 2500;

        int res = hi;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(func(grid,mid))
            {
                res = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return res;
        
    }
};
