class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size(), r = 0;
        
        for(int c = 0; c < m; c++){
            priority_queue<int, vector<int>, greater<int>> pq;
            
            for(int i = r, j = c; i < n and j < m; i++, j++)
                pq.push(mat[i][j]);
            
            for(int i = r, j = c; i < n and j < m; i++, j++)
                mat[i][j] = pq.top(), pq.pop();
            
        }
        
        int c = 0;
        for(int r = 1; r < n; r++){
            priority_queue<int, vector<int>, greater<int>> pq;
            
            for(int i = r, j = c; i < n and j < m; i++, j++)
                pq.push(mat[i][j]);
            
            for(int i = r, j = c; i < n and j < m; i++, j++)
                mat[i][j] = pq.top(), pq.pop();
            
        }
        
        return mat;
    }
};