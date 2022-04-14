class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ref = matrix;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    
                    for(int k = 0; k < matrix.size(); k++)
                        ref[k][j] = 0;
                    
                    for(int k = 0; k < matrix[i].size(); k++)
                        ref[i][k] = 0;
                    
                }
            }
        }
        matrix = ref;
    }
};