class Solution {
public:
    
    bool bfs(pair<int, int> source, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        queue<pair<int, int>> q;
        
        q.push(source);
        
        int n = grid.size(), m = grid[0].size();
        
        while(!q.empty()){
            
            auto parent = q.front();
            q.pop();
            
            if(vis[parent.first][parent.second]) continue;
            
            vis[parent.first][parent.second] = true;
            
            vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
            
            for(auto x : dir){
                
                int dx = x[0] + parent.first, dy = x[1] + parent.second;
                
                if(dx >= 0 and dy >= 0 and dx < n and dy < m && vis[dx][dy] == false && grid[dx][dy] == '1')
                    q.push({dx, dy});
                
            }
            
        }
    
        return true;    
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int islands = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                
                if(grid[r][c] == '1' && vis[r][c] == false){
                    islands += bfs({r, c}, grid, vis);
                    
                    // for(auto x : vis){
                    //     for(auto y : x){
                    //         cout << y << " ";
                    //     }
                    //     cout << endl;
                    // }
                    // cout << endl;
                    
                }
                
            }
        }
        
        return islands;
    }
};