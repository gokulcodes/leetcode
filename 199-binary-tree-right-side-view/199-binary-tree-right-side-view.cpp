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
    vector<int> arr;
    
    vector<int> bfs(TreeNode* root){
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int last = -1;
            int cnt = q.size();
            
            while(cnt--){
                
                TreeNode* top = q.front();
                q.pop();
                
                if(top->left != NULL){
                    q.push(top->left);
                }
                
                if(top->right != NULL){
                    q.push(top->right);
                }
                
                last = top->val;
                
            }
            
            arr.push_back(last);
            
        }
        
        return arr;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        return bfs(root);
    }
};