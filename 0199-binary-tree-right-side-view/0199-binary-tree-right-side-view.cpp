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
    void bfs(vector<vector<int>>& levels, int level, TreeNode* root){
        if(root == nullptr) return;
        
        if(levels.size() <= level){
            levels.push_back({});
        }

        levels[level].push_back(root->val);

        bfs(levels, level + 1, root->left);
        bfs(levels, level + 1, root->right);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> levels;
        vector<int> ans;
        bfs(levels, 0, root);

        for(auto& nodes:levels){
            int last = nodes.back();

            ans.push_back(last);
        }

        return ans;
    }
};