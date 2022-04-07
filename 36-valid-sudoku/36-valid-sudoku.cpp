class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool possible = true;
        int n = board.size();
        
        set<char> s;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] >= '1' and board[i][j] <= '9'){
                    if( s.count(board[i][j]) == 0){
                        s.insert(board[i][j]);
                    }else{
                        possible = false;
                    }     
                }
            }
            s.clear();
        }
        if(!possible) return possible;
        s.clear();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[j][i] >= '1' and board[j][i] <= '9'){
                    if(s.count(board[j][i]) == 0){
                        s.insert(board[j][i]);
                    }else{
                        possible = false;
                    }     
                }
            }
            s.clear();
        }
        
        if(!possible) return possible;
        s.clear();
        
        for(int l = 0; l < n; l+=3){
            for(int k = 0; k < n; k+=3){
                for(int i = k; i < k + 3; i++){
                    for(int j = l; j < l + 3; j++){
                        if(board[i][j] >= '1' and board[i][j] <= '9'){
                            if(s.count(board[i][j]) == 0){
                                s.insert(board[i][j]);
                            }else{
                                possible = false;
                            }
                        }
                    }
                }
                s.clear();
                if(!possible) return possible;
            }
        }
                
        return possible;
    }
};