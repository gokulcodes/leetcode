class Solution {
public:
    string getSmallestString(int n, int k) {
        int mod = k % 26;
        string res = string(k / 26, 'z');
        if(mod) res = string(1, (mod - 1) + 'a') + res;
        
        int curr = res.length(), i = 0;
        string newString = "";
        
        while(curr + newString.length() < n && i < res.length()){
            if(res[i] > 'a'){
                res[i]--;
                newString.append("a");
            }else i++;
        }
        
        return newString + res;
    }
};