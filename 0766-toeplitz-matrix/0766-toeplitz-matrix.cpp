class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            int c = i, r = 0, f = matrix[0][i];
            
            while(r < n and c < m){
                if(matrix[r][c] == f)
                    c++, r++;
                else return false;
            }
            
        }
        
        for(int i = 1; i < n; i++){
            int r = i, c = 0, f = matrix[i][0];
            
            while(r < n and c < m){
                if(matrix[r][c] == f)
                    c++, r++;
                else return false;
            }
        }
        
        return true;
    }
};