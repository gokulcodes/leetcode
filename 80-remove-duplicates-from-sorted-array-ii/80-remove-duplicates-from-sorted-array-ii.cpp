class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int last = n;
        
        map<int, int> m;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] == nums.back()) m[nums[i]]++;
            else break;
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] == nums.back()){
                if(m[nums[i]] > 2){
                    last -= (m[nums[i]] - 2);
                }
                break;
            }
            
            auto it = distance(nums.begin(), lower_bound(nums.begin(), nums.begin() + last, nums[i]));
            auto it1 = distance(nums.begin(), upper_bound(nums.begin(), nums.begin() + last, nums[i]));
            
            int cnt = it1 - it;
            
            if(cnt > 2){
//                 cout << nums[i] << " " << last << endl;
                
//                 for(auto x : nums) cout << x << " ";
//                 cout << endl;
                
                int s = it1;
                for(int j = it + 2; j < n && s < n; j++, s++){
                    nums[j] = nums[s];
                }
                last -= (cnt - 2);
            }
            // cout << last << endl;
        }
        
        
        
        return last;
    }
};