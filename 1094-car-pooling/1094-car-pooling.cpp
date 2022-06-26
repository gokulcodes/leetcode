class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [&](auto x, auto y){
           return x[1] < y[1];
        });
        
        int n = trips.size(), people = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int> > > > pq;
        
        for(int i = 0; i < n; i++){
            
            // if(!pq.empty()){
            //     cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.second << endl;
            // }
            
            while(!pq.empty() && pq.top().first <= trips[i][1]){
                people -= pq.top().second.second;
                pq.pop();
            }
            
            // cout << people << endl;
            
            if(people + trips[i][0] <= capacity){
                
                pq.push({ trips[i][2], { trips[i][1], trips[i][0] } });
                people += trips[i][0];
                
            }else return false;
            
            
            
        }
        
        return true;
    }
};