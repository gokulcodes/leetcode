class Solution {
public:
    int n, m;
    void bfs(queue<pair<int, int>> q, vector<vector<int>>& vis, vector<vector<int>>& heights){
        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            
            vis[sr][sc] = 1;
            
            vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
            
            for(auto x : dir){
                int dx = x[0] + sr, dy = x[1] + sc;
                
                if(dx >= 0 and dy >= 0 and dx < n and dy < m and vis[dx][dy] == 0 and heights[dx][dy] >= heights[sr][sc])
                    q.push({dx, dy});
                
            }
            
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> visp(n, vector<int>(m, 0)), visa(n, vector<int>(m, 0)), mountains;
        queue<pair<int, int>> pq, aq;
        
        for(int i = 0; i < n; i++) pq.push({i, 0});
        for(int j = 0; j < m; j++) pq.push({0, j});
        
        for(int i = 0; i < n; i++) aq.push({i, m-1});
        for(int j = 0; j < m; j++) aq.push({n-1, j});
        
        bfs(pq, visp, heights);
        bfs(aq, visa, heights);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visp[i][j] == 1 and visa[i][j])
                    mountains.push_back({i, j});
            }
        }
        
        return mountains;
    }
};