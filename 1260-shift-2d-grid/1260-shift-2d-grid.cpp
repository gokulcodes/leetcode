class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // if(grid.size() == 1 && grid[0].size() == 1) return grid;

        int n = grid.size(), m = grid[0].size();
        
        while(k--){
            int next_el = INT_MIN, prev_el = INT_MIN;
            for(int i = 0; i < n; i++){
                if(grid[i].size() > 1)
                    for(int j = 0; j < m; j++){
                        if(next_el == INT_MIN && j + 1 < m){
                            next_el = grid[i][j+1];
                            grid[i][j+1] = grid[i][j];
                            j++;
                        }else if(next_el != INT_MIN){
                            int temp = grid[i][j];
                            grid[i][j] = next_el;
                            next_el = temp;
                        }
                    }
                else 
                    if(prev_el == INT_MIN && i + 1 < n){
                        prev_el = grid[i+1][0];
                        grid[i+1][0] = grid[i][0];
                        i++;
                    } else {
                        int t = grid[i][0];
                        grid[i][0] = prev_el;
                        prev_el = t;
                    }
            } 
            if(prev_el != INT_MIN)
                grid[0][0] = prev_el;
            else grid[0][0] = next_el;
        }
        
        // for(auto x : grid){
        //     for(auto y : x) cout << y << " ";
        //     cout<< endl;
        // }
        
        return grid;
        
    }
};