class MyHashSet {
public:
    vector<list<int>> arr;
    int s;
    MyHashSet() {
        s = 1100;
        arr.resize(s);
    }
    
    list<int>::iterator search(int key){
        int i = key % s;
        return find(arr[i].begin(), arr[i].end(), key);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i = key % s;
        arr[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = key % s;
        arr[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = key % s;
        if(search(key) != arr[i].end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */