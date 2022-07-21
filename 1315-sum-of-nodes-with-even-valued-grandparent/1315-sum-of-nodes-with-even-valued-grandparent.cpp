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
    int sum = 0;
    
    void dfs(TreeNode* root){
        if(root == NULL) return;
        
        if(root->val % 2 == 0){
            cout << root->val << endl;
            TreeNode* temp = NULL;
            if(root->left != NULL) temp = root->left;
            if(temp and temp->left != NULL) sum += temp->left->val, cout << temp->left->val << " ";
            if(temp and temp->right != NULL) sum += temp->right->val, cout << temp->right->val << " ";
            
            cout << " | ";
            
            temp = NULL;
            
            if(root->right != NULL) temp = root->right;
            if(temp and temp->left != NULL) sum += temp->left->val, cout << temp->left->val << " ";
            if(temp and temp->right != NULL) sum += temp->right->val, cout << temp->right->val << " ";
        }
        cout << endl;
        
        dfs(root->left);
        dfs(root->right);
        
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return sum;
    }
};

// 16 + 78 + 91 + 27 + 71 + 71
