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
class Solution{
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root==NULL) return NULL;

        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};


// Original Tree:               Inverted Tree:
//         1                           1
//       /   \                       /   \
//      2     3                     3     2
//     / \   / \                   / \   / \
//    4   5 6   7                 7   6 5   4
//   / \ / \                           / \ / \
//  8  9 10 11                       11 10 9  8
//
// Level 0: [1]        -> [1]
// Level 1: [2,3]      -> [3,2]  
// Level 2: [4,5,6,7]  -> [7,6,5,4]
// Level 3: [8,9,10,11] -> [11,10,9,8]
//
// Step-by-step execution:
// 1. invertTree(1): swap(2,3) -> call invertTree(3), invertTree(2)
// 2. invertTree(3): swap(6,7) -> call invertTree(7), invertTree(6)  
// 3. invertTree(7): no children, return
// 4. invertTree(6): no children, return
// 5. invertTree(2): swap(4,5) -> call invertTree(5), invertTree(4)
// 6. invertTree(5): no children, return
// 7. invertTree(4): swap(8,9) -> call invertTree(9), invertTree(8)
// 8. invertTree(9): no children, return
// 9. invertTree(8): no children, return