class Solution {
public:
    
    int mxIsland = 0;
    
    map<pair<int, int>, bool> vis;
    
    void bfs(int r, int c, vector<vector<int>>& grid){
        
        queue<pair<int, int>> q;
        q.push({r, c});
        
        vector<vector<int>> dir = {{-1,0}, {0,-1},{1,0},{0,1}};
        int local = 0;
        
        vis[{r, c}] = true;
        
        while(!q.empty()){
            auto island = q.front();
            q.pop();
            
            local++;
            
            // cout << island.first << " " << island.second << endl;    
            
            for(auto x : dir){
                int dx = x[0] + island.first, dy = x[1] + island.second;
                
                if(dx >= 0 and dx < grid.size() and dy >= 0 and dy < grid[0].size()){
                    
                    if(grid[dx][dy] == 1 and !vis[{dx, dy}]){
                        
                        q.push({dx, dy});
                        vis[{dx, dy}] = true;
                        
                    }
                    
                }
                
            }
            
        }
        
        mxIsland = max(local, mxIsland);
        
        // cout << endl;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                
                if(!vis[{i, j}] and grid[i][j] == 1){
                    // cout << i << " " << j << endl;
                    bfs(i, j, grid);
                }
                
            }
        }
        
        return mxIsland;
    }
};