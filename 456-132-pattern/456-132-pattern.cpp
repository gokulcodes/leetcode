class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        
        int currMin = nums[0];
        
        for(auto x : nums){
            while(!st.empty() and x >= st.top().first){
                st.pop();
            }
            if(!st.empty() and x > st.top().second)
                return true;
            
            st.push({x, currMin});
            currMin = min(currMin, x);
        }
        
        return false;
    }
};