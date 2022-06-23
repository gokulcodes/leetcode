class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), [&](auto x, auto y){
           return x[1] < y[1]; 
        });
        
        priority_queue<int> pq;
        
        int total = 0;
        for(auto x : courses){
            int d = x[0], l = x[1];
            
            total += d;
            pq.push(d);
            
            while(total > l){
                total -= pq.top();
                pq.pop();
            }
            
        }
        
        return pq.size();
        
    }
};