class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int, int>, int>> q;
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dist[r][c] = steps;
            
            vector<vector<int>> dis = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            
            for(auto x : dis){
                int dx = x[0] + r, dy = x[1] + c;
                if(dx >= 0 and dy >= 0 and dx < n and dy < m and vis[dx][dy] == 0){
                    
                    q.push({{dx, dy}, steps + 1});
                    vis[dx][dy] = 1;
                    
                }
            }
            
        }
        
        return dist;
        
    }
};