class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> ts(m);
        
        int i = 0;
        
        for(int c = 0; c < m; c++){
            for(int r = 0; r < n; r++){
                 ts[i].push_back(matrix[r][c]);
            }  
            i++;
        }
        
        return ts;
    }
};