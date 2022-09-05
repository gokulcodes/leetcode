/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> order;
        if(root == NULL) return order;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> level;
            
            int size = q.size();
            while(size--){
                Node* top = q.front();
                q.pop();
                
                level.push_back(top->val);
                for(auto x : top->children){
                    q.push(x);
                }
                
            }
            order.push_back(level);
        }
        
        return order;
    }
};