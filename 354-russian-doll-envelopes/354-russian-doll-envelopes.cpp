class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](auto x, auto y){
            return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        });
        vector<int> best;   
        
        for(int i = 0; i < envelopes.size(); i++){
            int id = distance(best.begin(), lower_bound(best.begin(), best.end(), envelopes[i][1]));
            
            if(id >= best.size()){
                best.push_back(envelopes[i][1]);
            }else{
                best[id] = envelopes[i][1];
            }
            
        }
        
        return best.size();
    }
};