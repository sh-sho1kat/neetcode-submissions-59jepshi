class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i+=3)
        {
            for(int j = 0;j<9;j+=3)
            {
                int mp[10]={};
                for(int k = i;k<i+3;k++)
                {
                    for(int l = j;l<j+3;l++)
                    {
                        if(board[k][l]!='.')
                        {
                            if(mp[board[k][l]-'0'])
                                return false;
                            mp[board[k][l]-'0']++;
                        }
                    }
                }
            }
        }

        for(int i = 0;i<9;i++)
        {
            int mp1[10] = {};
            int mp2[10] ={};
            for(int j = 0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(mp1[board[i][j]-'0'])
                        return false;
                    mp1[board[i][j]-'0']++;
                }
                if(board[j][i]!='.')
                {
                    if(mp2[board[j][i]-'0'])
                        return false;
                    mp2[board[j][i]-'0']++;
                }
            }
        }
        return true;
    }
};
