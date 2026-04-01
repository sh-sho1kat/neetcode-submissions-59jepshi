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
    bool f = true;
    pair<int,int> dfs(TreeNode* node)
    {
        int mn = node->val;
        int mx = node->val;

        if(node->left)
        {
            pair<int,int> cur = dfs(node->left);
            if(cur.second>=node->val)
                f = false;
            mn = min(mn,cur.first);
            mx = max(mx,cur.second);
        }
        if(node->right)
        {
            pair<int,int> cur = dfs(node->right);
            if(cur.first<=node->val)
                f = false;
            mn = min(mn,cur.first);
            mx = max(mx,cur.second);
        }
        return {mn,mx};
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        dfs(root);
        return f;
    }
};
