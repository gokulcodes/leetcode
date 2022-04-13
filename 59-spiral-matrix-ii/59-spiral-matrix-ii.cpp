class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r = 0, c = 0, ptr = 1;
        
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        
        while(ptr <= n*n){
            for(int j = c; j < n; j++){
                if(matrix[r][j] == -1) matrix[r][j] = ptr, ptr++, c++;
            }
            r++, c--;
            for(int i = r; i < n; i++){
                if(matrix[i][c] == -1) matrix[i][c] = ptr, ptr++, r++;
            }
            
            r--, c--;
            for(int j = c; j >= 0; j--){
                if(matrix[r][j] == -1) matrix[r][j] = ptr, ptr++, c--;
            }
            
            r--, c++;
            for(int i = r; i >= 0; i--){
                if(matrix[i][c] == -1) matrix[i][c] = ptr, ptr++, r--;
            }
            
            r++;
            c = r;
            
//             for(auto x : matrix){
//                 for(auto y : x){
//                     cout << y << " ";
//                 }
//                 cout << endl;
//             }
            
//             cout << endl;
        }
        
        return matrix;
    }
};