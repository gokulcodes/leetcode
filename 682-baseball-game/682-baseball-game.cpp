class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        deque<int> q;
            
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "C"){
                q.pop_back();
            }else if(ops[i] == "D"){
                int one = q.back();
                q.push_back(2 * one);
            }else if(ops[i] == "+"){
                int one  = q.back();
                q.pop_back();
                int two = q.back();
                q.pop_back();
                int three = one + two;
                q.push_back(two);
                q.push_back(one);
                q.push_back(three);
            }else{
                // cout << stoi(ops[i]) << endl;
                q.push_back(stoi(ops[i]));
            }
            
        }
        
        int sum = 0;
        while(!q.empty()){
            // cout << q.back() << endl;
            sum += q.back();
            q.pop_back();
        }
        
        return sum;
    }
};