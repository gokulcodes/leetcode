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
    map<int, vector<pair<int, int>>> dic; 
    void dfs(TreeNode* root, int r, int c){
        if(root == NULL) return;
        
        dic[c].push_back({r, root->val});
        
        dfs(root->left, r + 1, c - 1);
        dfs(root->right, r + 1, c + 1);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        
        vector<vector<int>> res;
        for(auto &x : dic){
            sort(x.second.begin(), x.second.end(), [&](auto x, auto y){
                return x.first == y.first ? x.second < y.second : x.first < y.first;
            });
            
            vector<int> temp;
            for(auto &y : x.second) temp.push_back(y.second);
            res.push_back(temp);
        }
        
        return res;
    }
};