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
    map<int, int> mp;
    
    int r;
    
    TreeNode* construct(int s, int e, vector<int>& post) {
        if(s > e || r < 0) return NULL;
        
        int rootVal = post[r--];
//         if(alter) rootVal = post[r--];
//         if(!alter) rootVal = post[l++];
            
//         alter ^= 1;
        
        TreeNode* root = new TreeNode(rootVal);
        
        root->right = construct(mp[rootVal] + 1, e, post);
        root->left = construct(s, mp[rootVal] - 1, post);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        
        r = postorder.size() - 1;
        
        return construct(0, postorder.size() - 1, postorder);
    }
};

// postorder - left -> right -> root
// inorder - left -> root -> right

