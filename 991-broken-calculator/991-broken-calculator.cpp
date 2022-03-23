class Solution {
public:
    int brokenCalc(int st, int tr, int cnt = 0) {
        if(st >= tr){
            return (st - tr) + cnt;
        }
        
        int l = tr;
        if(tr&1) l++, cnt++;
        
        while(l % 2 == 0 && l > st) l /= 2, cnt++;
        
        return brokenCalc(st, l, cnt);
    }
};