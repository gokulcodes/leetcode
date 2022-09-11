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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;

        if(root == NULL) return res;
        
        TreeNode* node = root;
        st.push(node);
        
        while(!st.empty()){
            TreeNode* top = st.top();
            res.push_back(top->val);
            st.pop();
            
            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};