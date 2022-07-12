class Solution {
public:
    
    int n;
    vector<int> visited;
    
    bool dfs(vector<int>& matchsticks, int numsIndex, int currSum, int subsetSum, int k){
        
        if(k == 1)
            return true;
        if(currSum == subsetSum) {
            return dfs(matchsticks, n-1, 0, subsetSum, k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum + matchsticks[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += matchsticks[i];
            
            if(dfs(matchsticks, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= matchsticks[i];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& ms) {
        n = ms.size();
        
        visited.resize(16, 0);
        
        long long total = accumulate(ms.begin(), ms.end(), 0);
        
        if(total % 4) return false;
        
        int side = total / 4;
        
        vector<int> sums(4, 0);
        
        visited[n - 1] = 1;
        
        return dfs(ms, n - 1, ms[n - 1], side, 4);
        
    }
};
