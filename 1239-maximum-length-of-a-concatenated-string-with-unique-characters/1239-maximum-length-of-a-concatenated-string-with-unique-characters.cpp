class Solution {
public:
    
    int f(int i, string& s, vector<string>& arr){
        if(i >= arr.size()) {
            return s.length();
        }
        
        int pick = 0, flag = 1;
        string newS = s + arr[i];
        map<char, int> uni;
        for(auto &x : newS) {
            uni[x]++;
            if(uni[x] > 1) {
                flag = 0;
                break;
            }
        }
        
        if(flag) pick = f(i + 1, newS, arr);
        int not_pick = f(i + 1, s, arr);
        
        return max(pick, not_pick);
        
    }
    
    int maxLength(vector<string>& arr) {
        string empty = "";
        return f(0, empty, arr);
    }
};