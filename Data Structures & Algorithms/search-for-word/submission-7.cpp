class Solution {
public:
    bool isvalid(int row, int col, int n, int m)
    {
        
        if(row<0 or row>= n or col<0 or col>=m)
            return false;
        return true;
    }
    bool func(int row, int col, vector<vector<char>>& board, string &word,int pos,vector<vector<int>>vis)
    {
        if(vis[row][col])
            return false;
        vis[row][col] = true;

        // cout<<board[row][col];
        if(word[pos]!=board[row][col])
            return false;
        
        if(pos+1>=word.size())
            return true;
        bool f = false;
        int n = board.size();
        int m = board[0].size();
        if(isvalid(row+1,col,n,m))
            f |= func(row+1,col,board,word,pos+1,vis);
        if(isvalid(row-1,col,n,m))
            f |= func(row-1,col,board,word,pos+1,vis);
        if(isvalid(row,col+1,n,m))
            f |= func(row,col+1,board,word,pos+1,vis);
        if(isvalid(row,col-1,n,m))
            f |= func(row,col-1,board,word,pos+1,vis);
        vis[row][col] = false;
        return f;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                vector<vector<int>> vis(n, vector<int>(m));
                bool f = func(i,j,board,word,0,vis);
                if(f)
                    return true;
            }
        }
        return false;
    }
};
