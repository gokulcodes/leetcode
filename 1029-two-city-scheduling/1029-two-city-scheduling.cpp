class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> acity;
        for(int i = 0; i < costs.size(); i++){
            acity.push_back({costs[i][0], costs[i][1], costs[i][0] - costs[i][1]});
        }
        
        sort(acity.begin(), acity.end(), [&](auto a, auto b){
            return a[2] < b[2];
        });
        
        int n = costs.size() / 2, minCost = 0;
        
        for(int i = 0; i < n; i++) minCost += acity[i][0];
        
        for(int i = n; i < acity.size(); i++) minCost += acity[i][1];
        
        return minCost;
    }
};