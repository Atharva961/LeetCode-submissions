class RandomizedSet {
public:
    set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        int b_size = s.size();
        s.insert(val);
        int a_size = s.size();
        return a_size!=b_size;
    }
    
    bool remove(int val) {
        int b_size = s.size();
        s.erase(val);
        int a_size = s.size();
        return a_size!=b_size;
    }
    
    int getRandom() {
        vector<int> v(s.begin(), s.end());
        int ind = rand()%v.size();
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */