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
int height(TreeNode*root)
{
    if(root==nullptr) return 0;

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}
public:
    bool isBalanced(TreeNode* root) {
        
        if(root==nullptr) return true;

        if(root->left==nullptr && root->right==nullptr) return true;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        
        int height_left=height(root->left);
        int height_right=height(root->right);
        bool nodebalanced = abs(height_left-height_right) <= 1;

        return left && right && nodebalanced;

        
    }
};