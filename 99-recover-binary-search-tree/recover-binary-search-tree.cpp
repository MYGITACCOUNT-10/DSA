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
void updatebst(TreeNode*root,vector<int>&nodes,int &index)
{
    if(root==NULL) return;

    updatebst(root->left,nodes,index);
    root->val=nodes[index++];
    updatebst(root->right,nodes,index);

}
void inorder(TreeNode*root,vector<int>&nodes)
{
    if(root==NULL) return ;

    inorder(root->left,nodes);
    nodes.push_back(root->val);
    inorder(root->right,nodes);
}
public:
    void recoverTree(TreeNode* root) {

        vector<int>nodes;
        inorder(root,nodes);
        sort(nodes.begin(),nodes.end());

        int index=0;
        updatebst(root,nodes,index);


        
    }
};