#include <bits/stdc++.h>

class Solution {
public:
    
    map<int, deque<int>> m;
    
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) continue;
            
            int f = k - nums[i];
            
            if(m.find(f) != m.end() and m[f].size() != 0){
                int id = m[f].front();
                if(id != i){
                    // cout << i << " " << id << endl;
                    m[f].pop_front();
                    m[nums[i]].pop_front();
                    nums[i] = -1, nums[id] = -1;
                    ans++;
                }
            }

            // for(auto x : nums) cout << x << " ";
            // cout << endl;
        }
        
        return ans;
    }
};