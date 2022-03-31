class Solution {
public:
    void permute(int idx, vector<int>& s, vector<vector<int>>& res){
        if(idx == s.size()){
            res.push_back(s);
            return;
        } 

        for(int i = idx; i < s.size(); i++){
            swap(s[i], s[idx]);
            permute(idx+1, s, res);
            swap(s[i], s[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(0, nums, res);
        return res;
    }
};