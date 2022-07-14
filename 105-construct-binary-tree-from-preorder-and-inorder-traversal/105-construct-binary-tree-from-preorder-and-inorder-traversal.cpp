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
    map<int, int> ind;
    
    int ptr = 0;
    
    TreeNode* construct(int s, int e, vector<int>& pre){
        if(s > e) return NULL;
        
        int rootVal = pre[ptr++];
        TreeNode* root = new TreeNode(rootVal);
        
        int md = ind[rootVal];
        root->left = construct(s, md - 1, pre);
        root->right = construct(md + 1, e, pre);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) ind[inorder[i]] = i;
        
        return construct(0, preorder.size() - 1, preorder);
    }
};