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
private:
    void findDepth(int d, TreeNode* root){
        if(root == NULL) return;
        depth[root->val] = d;
        maxDepth = max(maxDepth, d);
        findDepth(d+1, root->left);
        findDepth(d+1, root->right);
    }

    TreeNode* lca(TreeNode* root){
        // if root is null or the node is maxdepth return the node
        // traverse left and right of the node
        // if left and right both return child then return currnode
        // else return the not null node from the children

        if(root == NULL || depth[root->val] == maxDepth){
            return root;
        }

        TreeNode* left = lca(root->left);
        TreeNode* right = lca(root->right);

        if(left && right){
            return root;
        }

        return left == NULL ? right : left;
    }

public:
    int maxDepth = INT_MIN;
    unordered_map<int,int> depth;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        findDepth(0, root);
        TreeNode* newroot = lca(root);
        return newroot;
    }
};