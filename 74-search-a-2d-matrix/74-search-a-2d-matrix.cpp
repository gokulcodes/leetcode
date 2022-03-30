class Solution {
public:
    int r = 0;
    
    void findRowIndex(int s, int e, vector<vector<int>>& matrix, int target){
        if(s > e) return;
        
        int md = (s + e) / 2;
        
        if(matrix[md][0] <= target && matrix[md][matrix[0].size() - 1] >= target) {
            r = md;
            return;
        }
        
        if(matrix[md][0] > target){
            r = md;
            findRowIndex(s, md - 1, matrix, target);
        }else if(matrix[md][0] < target){
            r = md;
            findRowIndex(md + 1, e, matrix, target);
        }
    }
    
    bool binarySearch(int s, int e, vector<vector<int>>& matrix, int target, int r){
        if(s > e) return false;
        int md = (s + e) / 2;
        if(matrix[r][md] == target) return true;
        
        if(matrix[r][md] > target)
            return binarySearch(s, md - 1, matrix, target, r);
        
        return binarySearch(md + 1, e, matrix, target, r);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        findRowIndex(0, matrix.size() - 1, matrix, target);
        cout << r << endl;
        return binarySearch(0, matrix[r].size() - 1, matrix, target, r);
    }
};