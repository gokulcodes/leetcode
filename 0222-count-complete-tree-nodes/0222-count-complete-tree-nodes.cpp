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
    int c = 0;
    void cnt(TreeNode* root){
        if(root == NULL) return;
        cnt(root->left);
        c++;
        cnt(root->right);
    }
    
    int countNodes(TreeNode* root) {
        cnt(root);
        return c;
    }
};