/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    
    int guessNumber(int n) {
        int l = 1, r = n;
        
        while(l <= r){
            int g = l + (r - l) / 2;
            int res = guess(g);
            
            if(res == -1) r = g - 1;
            else if(res == 1) l = g + 1;
            else return g;
        }
        
        return -1;
    }
};