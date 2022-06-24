class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        
        pq.push(a), pq.push(b), pq.push(c);
        
        int cnt = 0;
        
        while(true){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            
            // cout << t1 << " " << t2 << endl;
            
            if(t1 > 0 and t2 > 0){
                t1 -= 1, t2 -= 1;
                pq.push(t1);
                pq.push(t2);
                cnt++;
            }else break;
            
        }
        
        return cnt;
    }
};