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
    
    void dfs(TreeNode* root, TreeNode* &ref){
        if(root == NULL) return;
        dfs(root->right, ref);
        TreeNode* temp = new TreeNode(root->val);
        if(ref == NULL) ref = temp;
        else {
            temp->right = ref;
            ref = temp;
        }
        // cout << ref->val << endl;
        dfs(root->left, ref);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ref = NULL;
        dfs(root, ref);
        return ref;
    }
};