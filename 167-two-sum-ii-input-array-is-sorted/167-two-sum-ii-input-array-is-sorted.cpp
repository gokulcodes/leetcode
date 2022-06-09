class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for(int i = 0; i < n; i++){
            int tr = target - numbers[i];
            int id = distance(numbers.begin(), lower_bound(numbers.begin() + i + 1, numbers.end(), tr));
            
            if(id < numbers.size()){
                if(numbers[id] == tr){
                    return {i + 1, id + 1};
                }
            }
            
        }
        
        return {0, 0};
    }
};

// -1 + 2
//     1