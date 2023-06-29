class MyHashSet {
public:
    bool set[1000001];
    MyHashSet() {
        for (int i = 0; i < 1000001; i++) {
            set[i] = false;
        }
    }
    
    void add(int key) {
        set[key] = true;
    }
    
    void remove(int key) {
        set[key] = false;
    }
    
    bool contains(int key) {
        return set[key];
    }
};
