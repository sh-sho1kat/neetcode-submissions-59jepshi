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

    bool match(TreeNode* node1, TreeNode* node2)
    {
        if((node1 and !node2) or (!node1 and node2))
            return false;

        if(!node1 and !node2)
            return true;
        if(node1->val != node2->val)
            return false;

        bool res = true;

        res &= match(node1->left, node2->left);
        res &= match(node1->right, node2->right);

        return res;

    }

    bool travarse(TreeNode* node, TreeNode* subRoot)
    {
        bool res = match(node,subRoot);

        if(node->left)
            res |= travarse(node->left, subRoot);
        if(node->right)
            res |= travarse(node->right, subRoot);

        return res;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return travarse(root, subRoot);
    }
};
