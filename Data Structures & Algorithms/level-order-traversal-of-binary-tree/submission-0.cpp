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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;

        if(!root)
            return res;
        queue<TreeNode*>q1,q2;
        q1.push(root);

        while(!q1.empty() or !q2.empty())
        {
            vector<int>tmp;
            if(q1.size())
            {
                while(!q1.empty())
                {
                    TreeNode* node = q1.front();
                    q1.pop();
                    tmp.push_back(node->val);
                    if(node->left)
                        q2.push(node->left);
                    if(node->right)
                        q2.push(node->right);
                }
                res.push_back(tmp);
            }
            else
            {
                while(!q2.empty())
                {
                    TreeNode* node = q2.front();
                    q2.pop();
                    tmp.push_back(node->val);
                    if(node->left)
                        q1.push(node->left);
                    if(node->right)
                        q1.push(node->right);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};
