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
    
    void dfs(TreeNode* root, vector<vector<int>> &paths, vector<int> &path, int sum){
        if(root == NULL) return;
        
        if(root->left == NULL and root->right == NULL){
            
            auto total = accumulate(path.begin(), path.end(), 0);
            total += root->val;
            
            if(sum == total){
                path.push_back(root->val);
                paths.push_back(path);
                path.pop_back();
            }
            
            return;
        }
        
        path.push_back(root->val);
        dfs(root->left, paths, path, sum);
        dfs(root->right, paths, path, sum);
        path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        
        dfs(root, paths, path, targetSum);
        
        return paths;
        
    }
};