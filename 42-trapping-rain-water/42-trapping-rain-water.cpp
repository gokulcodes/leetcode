class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        queue<int> q;
        vector<int> left(n), right(n);
        
        for(int i = 0; i < n; i++){

            if(q.empty()){
                left[i] = i;
                q.push(i);
                continue;
            }
            
            while(!q.empty() and height[q.front()] < height[i]){
                q.pop();
            }
            
            q.push(i);
            
            left[i] = q.front();
            
        }

        while(!q.empty()) q.pop();
        
        for(int i = n - 1; i >= 0; i--){

            if(q.empty()){
                right[i] = i;
                q.push(i);
                continue;
            }
            
            while(!q.empty() and height[q.front()] < height[i]){
                q.pop();
            }
            
            q.push(i);
            
            right[i] = q.front();
            
        }
        
        
        for(int i = 0; i < n; i++){
            
            int curr = height[i], leftBar = height[left[i]], rightBar = height[right[i]];
            
            if(curr == leftBar || curr == rightBar) continue;
            
            // cout << min(leftBar, rightBar) - height[i] << endl;
            
            res += min(leftBar, rightBar) - height[i];
            
        }
        
        
        return res;
    }
};