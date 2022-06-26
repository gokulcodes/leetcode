class Solution {
public:
    int maxScore(vector<int>& pts, int k) {
        int n = pts.size();
        
        for(int i = 1; i < n; i++){
            pts[i] += pts[i - 1];
        }
        
        int l = -1, r = n - k, res = INT_MIN;
        
        while(l < k){
            
            int pos = (l >= 0 ? pts[l] : 0) + (pts[n - 1] - (r - 1 >= 0 ? pts[r - 1] : 0));
            res = max(pos, res);
            l++, r++;
            
        }
        
        return res;
    }
};
