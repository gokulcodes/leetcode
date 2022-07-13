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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            
            vector<int> arr;
            int cnt = q.size();
            
            while(cnt--){
                TreeNode* top = q.front();
                q.pop();    
                
                arr.push_back(top->val);
                
                if(top->left != NULL){
                    q.push(top->left);
                }
                
                if(top->right != NULL){
                    q.push(top->right);
                }
                
            }
            
            res.push_back(arr);
            
        }
        
        
        return res;
    }
};