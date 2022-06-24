class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        int t1 = pq.top();
        pq.pop();
        int t2 = pq.top();
        pq.pop();
        
        return (t1 - 1) * (t2 - 1);
    }
};