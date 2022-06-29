class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](auto x, auto y){
            return x[1] == y[1] ? x[0] > y[0] : x[1] < y[1];
        });
        
        vector<vector<int>> res;
        res.push_back(people[0]);
        
        int n = people.size();
        
        for(int i = 1; i < n; i++){
            
            int org = 0, j = 0;
            
            for(j = 0; j < res.size(); j++){
                
                if(people[i][0] <= res[j][0]) org++;
                if(org > people[i][1]) break;
                
            }
            
            res.push_back(people[i]);
            
            vector<int> temp = people[i];
            
            for(int k = i; k >= j and k - 1 >= 0; k--) res[k] = res[k - 1];
            
            res[j] = temp;
            
        }
        
        return res;
    }
};

// 5 7 6 7 5 4
// 0 0 1 1 2 4
