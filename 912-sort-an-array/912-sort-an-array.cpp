class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : nums) pq.push(x);
        
        int i = 0;
        while(!pq.empty()){
            nums[i] = pq.top();
            pq.pop();
            i++;
        }
        
        return nums;
    }
};