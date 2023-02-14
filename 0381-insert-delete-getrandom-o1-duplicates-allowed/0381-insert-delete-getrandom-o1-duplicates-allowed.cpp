class RandomizedCollection {
public:
    vector<int> v;
    map<int, set<int>> m;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size()-1);
        return m[val].size()==1;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if(it!=m.end())
        {
            auto free_pos = *it->second.begin();
            it->second.erase(free_pos);
            v[free_pos] = v.back();
            m[v.back()].insert(free_pos);
            m[v.back()].erase(v.size()-1);
            v.pop_back();
            if(it->second.size()==0)m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */