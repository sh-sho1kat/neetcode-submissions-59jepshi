class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int top_leftx = 0, top_lefty = 0;
        int top_rightx = 0, top_righty = n-1;
        int bottom_rightx = n-1, bottom_righty = n-1;
        int bottom_leftx = n-1, bottom_lefty = 0;

        int  i =1;

        cout<<top_leftx<<" "<<top_lefty<<endl;
        cout<<top_rightx<<" "<<top_righty<<endl;
        while(2*i<=n)
        {
            cout<<"ok"<<endl;
            int tlx = top_leftx, tly = top_lefty;
            int trx = top_rightx, tr_y = top_righty;
            int brx = bottom_rightx, bry = bottom_righty;
            int blx = bottom_leftx, bly = bottom_lefty;

            for(int j = top_lefty; j<top_righty; j++)
            {
                swap(matrix[tlx][tly],matrix[trx][tr_y]);
                swap(matrix[blx][bly],matrix[tlx][tly]);
                swap(matrix[blx][bly],matrix[brx][bry]);
                tly++;
                trx++;
                bry--;
                blx--;

            }
            top_leftx++;
            top_lefty++;

            top_rightx++;
            top_righty--;

            bottom_rightx--;
            bottom_righty--;

            bottom_leftx--;
            bottom_lefty++;

            i++;

        }

    }
};
