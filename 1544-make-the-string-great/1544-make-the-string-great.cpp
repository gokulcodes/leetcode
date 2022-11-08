class Solution {
public:
    
    bool isNot(char a, char b){
        if(islower(a) and isupper(b)){
            return a == tolower(b);
        }
        if(islower(b) and isupper(a)){
            return b == tolower(a);
        }
        return false;
    }
    
    string makeGood(string s) {
        int n = s.length(), flag = 0;
        
        while(!flag){
            flag = 1;
            string res = "";
            
            for(int i = 0; i < s.length(); i++){
            
                if(isNot(s[i], s[i + 1])){
                    flag = 0;
                    i++;
                }else{
                    res += string(1, s[i]);
                }

            }
            
            s = res;
        }
        
        return s;
    }
};