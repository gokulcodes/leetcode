class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, mx = INT_MIN;
        
        while(l <= r){
            int w = r - l, h = min(height[l], height[r]);
            mx = max(w * h, mx);
            if(height[l] < height[r]){
                l++;
            } else {
                r--;
            }
        }
        
        return mx;
    }
};