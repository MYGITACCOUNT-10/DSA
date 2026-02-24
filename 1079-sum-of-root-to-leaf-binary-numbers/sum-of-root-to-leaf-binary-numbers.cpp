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
int todecimal(string &s)
{
    int decimal=0;
    for(int i=0;i<s.size();i++)
    {
        int digit=s[i]-'0';
        int power= (s.size()-1)-i;

        decimal += digit * pow(2, power);
    }

    return decimal;
}
void solve(TreeNode* root, int &sum, string &s)
{
    if(root == NULL) return;

    char ch = root->val + '0';
    s.push_back(ch);

    if(root->left == NULL && root->right == NULL)
    {
        int dec = todecimal(s);
        sum += dec;
        s.pop_back();   
        return;
    }

    solve(root->left, sum, s);
    solve(root->right, sum, s);

    s.pop_back();
}
public:
    int sumRootToLeaf(TreeNode* root) {
        
        int sum=0;
        string s;
        solve(root,sum,s);

        return sum;
        
    }
};