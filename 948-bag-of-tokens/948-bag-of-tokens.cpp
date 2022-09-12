class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0, r = tokens.size() - 1, score = 0;
        int mx = 0;
        
        sort(tokens.begin(), tokens.end());
        
        while(l <= r){
            if(power >= tokens[l]){ // face-up
                power -= tokens[l];
                score++;
                l++;
            }else if(score){ // face-down
                power += tokens[r];
                score--;
                r--;
            } else break;
            // cout << power << " " << score << endl;
            mx = max(score, mx);
        }
        
        return mx;
    }
};