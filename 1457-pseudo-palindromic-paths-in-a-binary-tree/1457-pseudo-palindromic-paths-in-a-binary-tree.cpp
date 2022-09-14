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
    
    bool pal(map<int, int>& cnt){
        
        int odd = 0, even = 0;
        
        for(auto x : cnt) odd += x.second % 2;
        
        return odd == 1 || odd == 0;
    }
    
    int permute(TreeNode* root, map<int, int>& mp){
        if(root == NULL) return 0;
        
        if(root->left == NULL and root->right == NULL){
            map<int, int> temp = mp;
            temp[root->val]++;
            return pal(temp);
        }
        
        mp[root->val]++;
        int left = permute(root->left, mp);
        int right = permute(root->right, mp);
        mp[root->val]--;
        
        return left + right;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int> mp;
        return permute(root, mp);
    }
};