#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_multiset p;

        int n = nums.size();
        
        vector<int> res(n);
        
        for(int i = n - 1; i >= 0; i--){
            p.insert(nums[i]);
            res[i] = p.order_of_key(nums[i]);
        }
        
        return res;
    }
};