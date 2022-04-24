class UndergroundSystem {
public:
    map<int, pair<double, pair<string, string>>> m;
    map<pair<string, string>, pair<double, double>> ledger;
    
    UndergroundSystem() {
        
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id].first = t;
        m[id].second.first = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        double diff = t - m[id].first;
        ledger[{m[id].second.first, stationName}].first++;
        
        ledger[{m[id].second.first, stationName}].second += diff;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        // cout << ledger[{startStation, endStation}].first << endl;
        return ledger[{startStation, endStation}].second / ledger[{startStation, endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */