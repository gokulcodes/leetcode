class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        
        int n = heights.size();
        
        for(int i = 0; i < n - 1; i++){
            
            if(heights[i] < heights[i + 1]){
                
                int needed = heights[i + 1] - heights[i];
                
                pq.push(needed);
                bricks -= needed;
                
                while(!pq.empty() and ladders > 0 and bricks < 0){

                    bricks += pq.top();
                    pq.pop();
                    ladders -= 1;

                }

                if(bricks < 0) return i;
                
            }
            
        }
        
        return n - 1;
    }
};