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
class BSTIterator {
public:
    
    vector<int> itr;
    
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->right);
        itr.push_back(root->val);
        dfs(root->left);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        int t = itr.back();
        itr.pop_back();
        return t;
    }
    
    bool hasNext() {
        return itr.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */