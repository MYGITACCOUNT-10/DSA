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
    int maxLevelSum(TreeNode* root) {

        if(root==NULL) return 0;

        if(root->right==NULL && root->left==NULL) return 1;
        
        int max_sum=INT_MIN;
        int max_sum_level=1;
        queue<TreeNode*>q;
        q.push(root);
        int curr_lvl=0;

        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {   
                TreeNode*temp=q.front();
                sum+=(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            curr_lvl++;
            if(sum>max_sum)
            {
                max_sum=sum;
                max_sum_level=curr_lvl;
            } 
        }

        return max_sum_level;

    }
};