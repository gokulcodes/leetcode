class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int rem = 0, total = 0;
        
        for(auto x : piles) total += x;
        
        while(k--){
            int top = pq.top();
            pq.pop();
            rem += (top / 2);
            top -= (top / 2);
            
            if(top > 0) pq.push(top);
        }
        
        return total - rem;
    }
};