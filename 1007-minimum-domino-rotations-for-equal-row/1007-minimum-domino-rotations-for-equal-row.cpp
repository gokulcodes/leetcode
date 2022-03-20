class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        vector<int> cnt_t(7), cnt_b(7);
        for(auto x : tops) cnt_t[x]++;
        for(auto x : bottoms) cnt_b[x]++;
        
        auto x = max_element(cnt_t.begin(), cnt_t.end());
        auto y = max_element(cnt_b.begin(), cnt_b.end());
        int f = distance(cnt_t.begin(), x), s = distance(cnt_b.begin(), y);
        
        bool pos1 = true, pos2 = true;
        int cntTop = 0, cntBottom = 0;
        for(int i = 0; i < tops.size(); i++){
            if(tops[i] != f && bottoms[i] != f) {
                pos1 = false;
                break;
            }else if(tops[i] != f && bottoms[i] == f) cntTop++;
        } 
    
        for(int i = 0; i < bottoms.size(); i++){
            if(tops[i] != s && bottoms[i] != s) {
                pos2 = false;
                break;
            }else if(bottoms[i] != s && tops[i] == s) cntBottom++;
        }
        
        if(!pos1 && !pos2) return -1;
        
        if(!pos1 && pos2) return cntBottom;
        if(pos1 && !pos2) return cntTop;
        
        return min(cntTop, cntBottom);
    }
};