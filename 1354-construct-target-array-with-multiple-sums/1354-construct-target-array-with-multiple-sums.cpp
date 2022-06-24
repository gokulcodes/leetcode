class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        if(target.size() == 1) return target[0] == 1;
        
        priority_queue<int> pq(target.begin(), target.end());
        long long totalSum = accumulate(target.begin(), target.end(),  0ll);
        
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            
            if(top == 1) continue;
            int times = (top - 1) / (totalSum - top);
            int newPop = top - times * (totalSum - top);
            
            if(newPop == top) return false;
            totalSum -= top - newPop;
            
            if(newPop != 1) pq.push(newPop);
            
        }
        
        return true;
    }
};

