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

struct comparator{
    bool operator()(int x, int y){
        return x > y;
    }
};

class Solution {
public:
    
    priority_queue<int, vector<int>, comparator> q;
    
    int itr = 0, last = -1;
    
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->left);
        itr--;
        if(itr == 0)
            last = root->val;
        // q.push(root->val);
        dfs(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        itr = k;

        dfs(root);
                
        // int last = -1;
        // while(k > 0){
        //     last = q.top();
        //     q.pop();
        //     k--;
        // }
        
        return last;
    }
};