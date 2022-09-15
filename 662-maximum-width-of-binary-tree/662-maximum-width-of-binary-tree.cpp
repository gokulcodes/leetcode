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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int width = INT_MIN;
        
        while(!q.empty()){
            int size = q.size();
            
            int mx = 0, mn = 0, mmin = q.front().second;
            
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front().first;
                int id = q.front().second - mmin;
                q.pop();
                
                if(i == 0) mn = id;
                if(i == size - 1) mx = id;
                
                if(curr->left){
                    q.push({curr->left, (long long)id * 2 + 1});
                }

                if(curr->right){
                    q.push({curr->right, (long long)id * 2 + 2});
                }
                
            }
            
            cout << mx << " " << mn << endl;
            width = max(width, (mx - mn + 1));
            
        }
        
        return width;
    }
};