class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> myqueue;
        for(auto x : stones) myqueue.push(x);
        
        while(myqueue.size() > 1){
            
            int x = myqueue.top();
            myqueue.pop();
            int y = myqueue.top();
            myqueue.pop();
            
            if(x != y) myqueue.push(x - y);
            
        }
        
        return myqueue.size() ? myqueue.top() : 0;
    }
};