class Solution {
public:
    
    
    string intToRoman(int num) {
        map<int, char> m;
        m[1] = 'I';
        m[5] = 'V';
        m[10] = 'X';
        m[50] = 'L';
        m[100] = 'C';
        m[500] = 'D';
        m[1000] = 'M';
        
        int n = to_string(num).length();
        string res = "";
        
        cout << n << endl;
        
        while(n){
            int i = 1, div = 1;
            
            while(i < n){
                div *= 10;
                i++;
            }
            
            int p = num - (num % div);
            num -= p;
            int cnt = p / div;
            
            cout << p << " " << cnt << endl;
            
            if(cnt <= 3){
                res += string(cnt, m[div]);
            }else if(cnt == 4){
                
                if(p == 4){
                    res += "IV";
                }else if(p == 40){
                    res += "XL";
                }else if(p == 400){
                    res += "CD";
                }
                
            }else if(cnt == 5){
                
                if(p == 5){
                    res += "V";
                }else if(p == 50){
                    res += "L";
                }else if(p == 500){
                    res += "D";
                }
                
            }else if(cnt == 6){
            
                if(p == 6){
                    res += "VI";
                }else if(p == 60){
                    res += "LX";
                }else if(p == 600){
                    res += "DC";
                }
                
            }else if(cnt == 7){
            
                if(p == 7){
                    res += "VII";
                }else if(p == 70){
                    res += "LXX";
                }else if(p == 700){
                    res += "DCC";
                }
                
            }else if(cnt == 8){
            
                if(p == 8){
                    res += "VIII";
                }else if(p == 80){
                    res += "LXXX";
                }else if(p == 800){
                    res += "DCCC";
                }
                
            }else if(cnt == 9){
                
                if(p == 9){
                    res += "IX";
                }else if(p == 90){
                    res += "XC";
                }else if(p == 900){
                    res += "CM";
                }
                
            }else if(cnt == 10){
                res += string(1, m[p]);
            }
            
            n--;
            
        }
        return res;
    }
};