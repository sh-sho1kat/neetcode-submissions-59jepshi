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

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        bool res = true;
        if(root->left and root->right)
        {
            int p = getheight(root->left);
            int q = getheight(root->right);

            if(abs(p-q)>1)
                return false;
        }
        else if(root->left)
        {
            int p = getheight(root->left);
            int q = 0;

            if(abs(p-q)>1)
                return false;
        }

        else if(root->right)
        {
            int p = getheight(root->right);
            int q = 0;

            if(abs(p-q)>1)
                return false;
        }

        res &= isBalanced(root->left);
        res &= isBalanced(root->right);

        return res;
        
    }
};
