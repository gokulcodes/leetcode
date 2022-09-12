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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int flag = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            
            while(size){
                TreeNode* top = q.front();
                level.push_back(top->val);
                q.pop();
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                size--;
            }
            
            if(flag) reverse(level.begin(), level.end());
            res.push_back(level);
            
            flag ^= 1;
        }
        
        return res;
    }
};