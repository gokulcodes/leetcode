class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            bool found = binary_search(matrix[i].begin(), matrix[i].end(), target);
            if(found) return found;
            // for(int j = 0; j < matrix[i].size(); j++){
            //     if(matrix[i][j] == target) return true;
            // }
        }
        return false;
    }
};