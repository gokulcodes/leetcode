class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int j = people.size() - 1, i = 0, cnt = 0;
        
        while(i <= j){
            int sum = people[i] + people[j];
            if(sum <= limit){
                i++, j--;
                cnt++;
            }else if(sum > limit){
                j--;
                cnt++;
            }
        }
        
        return cnt;
    }
};