class Solution {
public:
    
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph){
        if(color[node] > 0)
            return color[node] == 2;
        
        color[node] = 1;
        for(auto x : graph[node]){
            if(color[x] == 2) continue;
            if(color[x] == 1 || !dfs(x, color, graph)){
                // cout << x << " " << color[x] << endl;
                return false;                
            }
        }
        
        color[node] = 2;

        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0), ans;
        
        for(int i = 0; i < n; i++){
            // cout << i << " " << dfs(i, color, graph) << endl;
            if(dfs(i, color, graph))
                ans.push_back(i);
        }
            
        
        return ans;
    }
};