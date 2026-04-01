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
    int res;
    bool flag = true;
    int dfs(TreeNode* node, int k,int cur)
    {
        if(!node)
            return 0;
        int cnt = 1;
        int c1 = 0, c2 = 0;
        if(node->left)
        {
            c1 = dfs(node->left,k,cur);
        }
        if(c1+1==k and flag)
            res = node->val,flag =false;
        if(node->right)
        {
            c2 = dfs(node->right,k, cur + c1 + 1);
        }
        if(cur+c1+1==k and flag)
            res = node->val,flag =false;
        cout<<node->val<<" "<<c1<<" "<<c2<<endl;
        
        return c1+c2+1;
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k,0);
        return res;
    }
};
