class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        
        vector<vector<int>> ref = board;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int lives = 0;
                if(j - 1 >= 0) lives += board[i][j - 1];
                if(j + 1 < m) lives += board[i][j + 1];
                if(i - 1 >= 0) lives += board[i - 1][j];
                if(i + 1 < n) lives += board[i + 1][j];
                if(i - 1 >= 0 and j - 1 >= 0) lives += board[i - 1][j - 1];
                if(i + 1 < n and j + 1 < m) lives += board[i + 1][j + 1];
                if(i - 1 >= 0 and j + 1 < m) lives += board[i - 1][j + 1];
                if(i + 1 < n and j - 1 >= 0) lives += board[i + 1][j - 1];
                
                if(ref[i][j] == 1){
                    if(lives < 2) ref[i][j] = 0;
                    else if(lives == 2 || lives == 3) ref[i][j] = 1;
                    else if(lives > 3) ref[i][j] = 0;
                }else{
                    if(lives == 3) ref[i][j] = 1;
                }
                
            }
        }
        
        board = ref;
    }
};