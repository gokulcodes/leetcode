class NumMatrix {
public:
    vector<vector<int>> mat;
    int n = 0, m = 0;
    
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        n = matrix.size(), m = matrix[0].size();
        for(int r = 0; r < n; r++){
            for(int c = 1; c < m; c++){
                mat[r][c] += mat[r][c - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        for(int r = row1; r <= row2; r++){
            int last = mat[r][col2];
            if(col1 - 1 >= 0){
                last -= mat[r][col1 - 1];    
            }
            sum += last;
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */