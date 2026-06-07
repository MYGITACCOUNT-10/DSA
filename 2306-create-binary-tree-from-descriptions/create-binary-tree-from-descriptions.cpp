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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, pair<int, int>> tree;

        // Build parent -> {left, right} map
        for (auto &itr : descriptions)
        {
            int parent = itr[0];
            int child = itr[1];
            int isLeft = itr[2];

            if (isLeft)
                tree[parent].first = child;
            else
                tree[parent].second = child;
        }

        // Store all children
        unordered_set<int> children;

        for (auto &itr : descriptions)
        {
            children.insert(itr[1]);
        }

   
        int root_node = -1;
        for (auto &itr : descriptions)
        {
            int parent = itr[0];

            if (children.find(parent) == children.end())
            {
                root_node = parent;
                break;
            }
        }

    
        unordered_map<int, TreeNode*> nodes;
        nodes[root_node] = new TreeNode(root_node);

        queue<int> q;
        q.push(root_node);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            TreeNode* curr = nodes[node];

            int lchild = tree[node].first;
            int rchild = tree[node].second;

            // Left child
            if (lchild)
            {
                if (nodes.find(lchild) == nodes.end())
                    nodes[lchild] = new TreeNode(lchild);

                curr->left = nodes[lchild];
                q.push(lchild);
            }

            // Right child
            if (rchild)
            {
                if (nodes.find(rchild) == nodes.end())
                    nodes[rchild] = new TreeNode(rchild);

                curr->right = nodes[rchild];
                q.push(rchild);
            }
        }

        return nodes[root_node];
    }
};