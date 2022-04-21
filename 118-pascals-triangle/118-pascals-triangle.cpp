class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;
        
        for(int i = 1; i <= numRows; i++){
            vector<int> v(i);
            v[0] = 1;
            v[i - 1] = 1;
            
            for(int j = 1; j < i - 1; j++){
                v[j] += (matrix[i - 2][j - 1] + matrix[i - 2][j]);
            }
            
            matrix.push_back(v);
        }
        
        return matrix;
    }
};