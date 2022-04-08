struct comparator {
     bool operator()(int i, int j) {
     return i > j;
    }
};

class KthLargest {
public:
    
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, comparator> minheap;
    
    int offset;
    
    KthLargest(int k, vector<int>& nums) {
        offset = k;
        
        for(auto x : nums) maxheap.push(x);
        for(int i = 0; i < k - 1; i++){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    int add(int val) {
        int large;
        if(maxheap.size() == 0){
            minheap.push(val);
            maxheap.push(minheap.top());
            minheap.pop();
            return maxheap.top();
        }
        if(maxheap.top() > val){
            maxheap.push(val);
            large = maxheap.top();
        }else if(maxheap.top() <= val){
            minheap.push(val);
            maxheap.push(minheap.top());
            large = maxheap.top();
            minheap.pop();
        }
        return large;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */