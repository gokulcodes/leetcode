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
    
    // int dfs(TreeNode* root, vector<int>& hash){
        // if(root == NULL) return 0;
        
//         if(root->left == NULL and root->right == NULL) {
//             hash.push_back(root->val);
//             for(auto x : hash) cout << x << " ";
//             cout << endl;
//             return 0;
//         }
        
//         hash.push_back(root->val);
        
//         if(root->left != NULL){
//             dfs(root->left, hash);
//             hash.pop_back();
//         }
        
//         for(auto x : hash) cout << x << " ";
//         cout << endl;
        
//         if(root->right != NULL){
//             dfs(root->right, hash);
//             hash.pop_back();        
//         }
        
//         return 0;
//     }
    
    int cnt = 1;
    void dfs(TreeNode* &root){
        if(root == NULL) return;
        
        if(root->left != NULL){
            if(root->val <= root->left->val) {
                // cout << root->val << " " << root->left->val << endl;
                cnt++;
            }
            root->left->val = max(root->val, root->left->val);
            dfs(root->left);    
        }
        
        if(root->right != NULL){
            if(root->val <= root->right->val) {
                // cout << root->val << " " << root->right->val << endl;
                cnt++;
            }
            root->right->val = max(root->val, root->right->val);
            dfs(root->right);    
        }
        
    }
    
    // void traverse(TreeNode* root){
    //     if(root==NULL) return;
    //     traverse(root->left);
    //     cout << root->val << endl;
    //     traverse(root->right);
    // }
    
    int goodNodes(TreeNode* root) {
        // vector<int> hash;
        dfs(root);
        // traverse(root);
        return cnt;
    }
};