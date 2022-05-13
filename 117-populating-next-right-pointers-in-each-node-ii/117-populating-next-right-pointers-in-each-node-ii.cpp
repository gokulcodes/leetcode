/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> q;
        q.push(root);
        
        
        while(!q.empty()){
            auto s = q.size();
            
            vector<Node*> temp;
            
            for(int i = 0; i < s; i++){
                Node* t = q.front();
                
                if(t and t->left){
                    q.push(t->left);
                }
                if(t and t->right){
                    q.push(t->right);
                }
                
                q.pop();
                temp.push_back(t);
            }
            
            if(temp.size() == 1 and temp[0])
                temp[0]->next = NULL;
            
            else
                for(int i = 0; i < temp.size() - 1; i++){
                    temp[i]->next = temp[i + 1];
                }
            
            // for(auto x : temp) cout << x->val << " ";
            // cout << endl;
        }
        
        return root;
    }
};