class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losers;
        set<int> players;
        
        vector<int> s1, s2;
        
        for(auto &x : matches){
            losers[x[1]]++;
            players.insert(x[0]);
            players.insert(x[1]);
        }
        
        for(auto &x : players){
            if(losers[x] == 0) s1.push_back(x);
            else if(losers[x] == 1) s2.push_back(x);
        }
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        return {s1, s2};
        
    }
};