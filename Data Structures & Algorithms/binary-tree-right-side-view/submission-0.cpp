/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int mxh = 0;
    vector<int>res;
    void dfs(TreeNode* node,int height)
    {
        if(!node)
            return;
        cout<<node->val<<" "<<height<<" "<<mxh<<endl;
        if(height >= mxh)
        {
            res.push_back(node->val);
            mxh++;
        }
        if(node->right)
            dfs(node->right,height+1);
        if(node->left)
            dfs(node->left,height+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
            return res;
        

    }
};
