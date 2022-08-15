class Solution {
public:
    int romanToInt(string s) {
        map<string, int> dic;
        dic["I"] = 1, dic["V"] = 5, dic["X"] = 10, dic["L"] = 50, dic["C"] = 100,
        dic["D"] = 500, dic["M"] = 1000, dic["IV"] = 4, dic["IX"] = 9, dic["XL"] = 40, 
        dic["XC"] = 90, dic["CD"] = 400, dic["CM"] = 900;
        
        int i = 0, n = 0;
        while(i < s.size()){
            string t = s.substr(i, 2);
            if(dic.find(t) == dic.end()){
                n += dic[s.substr(i, 1)];
                i+=1;
            }else{
                n += dic[t];
                i+=2;
            }
            
        }
        
        return n;
    }
};