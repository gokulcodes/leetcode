class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> curr, int f, int sum, int k){
        if(sum == 0){
            if(k == 0){
                res.push_back(curr);
            }
            return;
        }
        
        if(k == 0) return;
        
        if(f == 10) return;
        
        dfs(curr, f + 1, sum, k);
        if(sum - f >= 0){
            curr.push_back(f);
            dfs(curr, f + 1, sum - f, k - 1);
            curr.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        dfs(curr, 1, n, k);
        return res;
    }
};