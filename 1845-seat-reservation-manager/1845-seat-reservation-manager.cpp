class SeatManager {
public:
    vector<bool> vis;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    SeatManager(int n) {
        vis.resize(n + 1);
        for(int i = 1; i <= n; i++) vis[i] = true, pq.push(i);
    }
    
    int reserve() {
        
        int top = pq.top();
        pq.pop();
        
        vis[top] = false;
        
        return top;
        
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */