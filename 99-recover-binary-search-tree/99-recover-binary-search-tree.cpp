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
    int el = -1, el2 = -1;

    void dfs(TreeNode* root, vector<int> &sorted){
        if(root == NULL) return;
        dfs(root->left, sorted);
        sorted.push_back(root->val);
        dfs(root->right, sorted);
    }
    
    void swaper(TreeNode* &root){
        if(root == NULL) return;
        swaper(root->left);
        if(root->val == el) root->val = el2;
        else if(root->val == el2) root->val = el;
        swaper(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> sorted;
        dfs(root, sorted);
        
        vector<int> arr = sorted;
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != sorted[i] and el == -1) el = sorted[i];
            else if(arr[i] != sorted[i] and el2 == -1) el2 = sorted[i];
        }
        
        swaper(root);
        
    }
};
