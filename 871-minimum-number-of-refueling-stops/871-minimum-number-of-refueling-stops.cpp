class Solution {
public:
    
    int mn = INT_MAX;
    
    void minStops(int id, int pos, long long fuel, int stops, int target, vector<vector<int>>& stations){
        
        if(pos + fuel >= target) {
            mn = min(mn, stops);
            return;
        }
        
        if(id >= (int)stations.size()) return;
        
        for(int i = id; i < stations.size(); i++){
            
            long long atmost = pos + fuel;
            
            if(atmost < stations[i][0]) break;
            
            int spent = fuel - (stations[i][0] - pos);
            
            minStops(i, stations[i][0], spent + stations[i][1], stops + 1, target, stations);
            
        }
        
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        // minStops(0, 0, startFuel, 0, target, stations);
        
        int n = stations.size();
        vector<long long> dp(n + 1, 0);
        
        dp[0] = startFuel;
        
        for(int i = 0; i < n; i++){
            for(int t = i; t >= 0; t--){
                if(dp[t] >= stations[i][0]){
                    dp[t + 1] = max(dp[t + 1], dp[t] + (long long)stations[i][1]);
                }
            }
        }
        
        for(int i = 0; i <= n; i++){
            if(dp[i] >= target) return i;
        }
        
        return -1;
    }
};