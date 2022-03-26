class Solution {
public:
    map<int, vector<int>> adj;
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int, int>> st;
        
        for(auto x : roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            st.insert({x[0], x[1]});
        }
        
        int max_child = 0;
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                curr += adj[i].size() + adj[j].size();
                
                if(st.count({i, j}) || st.count({j, i})) curr--;
                
                max_child = max(curr, max_child);
                curr = 0;
            }
        }
        
        return max_child;
    }
};