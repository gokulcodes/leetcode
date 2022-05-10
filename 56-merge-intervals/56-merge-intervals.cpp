class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto x, auto y){
            return x[0] < y[0];
        });
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        int j = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            if(res[j][1] >= intervals[i][0]){
                res[j] = {min(intervals[i][0], res[j][0]), max(intervals[i][1], res[j][1])};
            }else{
                res.push_back(intervals[i]);
                j++;
            }
        }
        
        return res;
    }
};