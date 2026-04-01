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
    unordered_map<TreeNode*, int> height;

    int getheight(TreeNode* node)
    {
        if(!node)
            return 0;
        if(height[node])
            return height[node];
        int a= getheight(node->left);
        int b= getheight(node->right);
        return height[node] = max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        int h1 = 0, h2 = 0, res = 0;
        h1 = getheight(root->left);
        h2 = getheight(root->right);
        res = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));

        res = max(res,h1+h2);
        return res;

    }
};
