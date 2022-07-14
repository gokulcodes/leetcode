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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            
            while(top != NULL){
                st.push(top);
                top = top->left;
            }
            
            while(!st.empty()){
                TreeNode* t = st.top();
                res.push_back(t->val);
                st.pop();
                
                if(t->right != NULL){
                    st.push(t->right);
                    break;
                }
                
            }
            
        }
        
        return res;
    }
};