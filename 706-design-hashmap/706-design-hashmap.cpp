class MyHashMap {
public:
    vector<int> val;
    
    MyHashMap() {
        vector<int> arr(1000007, -1);
        this->val = arr;
    }
    
    void put(int key, int value) {
        val[key] = value;
    }
    
    int get(int key) {
        return val[key];
    }
    
    void remove(int key) {
        val[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */