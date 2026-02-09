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
    void traverse(TreeNode* root, vector<int>& vec){
        if(!root) return;
        traverse(root->left, vec);
        vec.push_back(root->val);
        traverse(root->right, vec);
    }

    TreeNode* solve(int l, int r, vector<int>& vec){

        if(l>r) return nullptr;

        int mid = l + (r-l)/2;
        TreeNode* ro = new TreeNode(vec[mid]);
        ro->left = solve(l, mid-1, vec);
        ro->right = solve(mid+1, r, vec);
        return ro;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        traverse(root, vec);
        int l = 0;
        int r = vec.size()-1;
        return solve(l, r, vec);
    }
};