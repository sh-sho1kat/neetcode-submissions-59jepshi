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
    unordered_map<int,int>mp;
    int idx = 0;
    TreeNode* dfs(vector<int>& preorder, int lo, int hi)
    {
        if(lo>hi)
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[idx]);
        int mid = mp[preorder[idx++]];
        node->left = dfs(preorder,lo,mid-1);
        node->right = dfs(preorder,mid+1,hi);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int lo = 0;
        int hi = inorder.size()-1;
        for(int i = 0;i<=hi;i++)
        {
            mp[inorder[i]]=i;
        }
        return dfs(preorder,lo,hi);
    }
};
