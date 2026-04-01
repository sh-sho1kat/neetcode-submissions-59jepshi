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
    int res= -1005;
    int dfs(TreeNode* node)
    {
        if(!node)
            return 0;
        int p = 0, q = 0;
        if(node->left)
            p = dfs(node->left);
        if(node->right)
            q = dfs(node->right);
        int mx = max({p,q,p+q})+node->val;
        cout<< node->val<<" "<<mx<<endl;
        res = max(res,mx);
        mx = max(p,q)+node->val;
        mx = max(mx,0);
        return mx;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
