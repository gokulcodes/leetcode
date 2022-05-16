class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size();
        
        if(grid[r - 1][c - 1] != 0 || grid[0][0] != 0) return -1;
        if(r == 1 and c == 1 and grid[0][0] == 0) return 1;
        
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 0});
        
        vector<vector<bool>> vis(r, vector<bool>(c));
        
        vis[0][0] = true;
        
        int cnt = INT_MAX, prev = 1;
        
        bool found = false;
        
        while(!q.empty()){
            auto t = q.front().first;
            q.pop();
            
            vector<vector<int>> dir = {{1,1},{1,-1},{-1,1},{0,1},{1,0},{-1,-1},{-1,0},{0,-1}};    
            
            for(auto x : dir){
                int dx = x[0] + t.first, dy = x[1] + t.second;
                
                if(dx >= 0 and dy >= 0 and dx < r and dy < c and !vis[dx][dy]){
                    
                    if(grid[dx][dy] == 0){
                        
                        q.push({{dx, dy}, prev + 1});
                        
                        prev = max(q.front().second, prev);
                        
                        if(dx == r - 1 and dy == c - 1 and !q.empty()){
                            found = true;
                            cnt = min(q.front().second, cnt);
                        }
                        
                    }
                    
                    vis[dx][dy] = true;
                }
                
            }
            
        }
        
        cnt = min(prev, cnt);
        
        return found ? cnt : -1;
    }
};