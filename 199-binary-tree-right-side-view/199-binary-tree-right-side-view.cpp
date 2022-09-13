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
    map<int, int> mp;
    
    void preorder(TreeNode* root, int level){
        if(root == NULL) return;
        
        if(mp.find(level) == mp.end()) mp[level] = root->val;
        
        preorder(root->right, level + 1);
        preorder(root->left, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        preorder(root, 0);
        
        for(auto x : mp) res.push_back(x.second);
        
        return res;
    }
};