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
    int dfs(TreeNode* node, int mxval)
    {
        if(!node)
            return 0;
        int res = 0;
        if(node->val>=mxval)
            res++;
        res += dfs(node->left,max(mxval,node->val));
        res += dfs(node->right,max(mxval,node->val));

        return res;
    }
    int goodNodes(TreeNode* root) {
        int res = dfs(root,-100000);
        return res;
    }
};
