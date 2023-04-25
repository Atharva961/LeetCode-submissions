class SmallestInfiniteSet {
public:
    int minn = 1;
    unordered_map<int, int> m;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int ans = minn;
        m[minn] = 1;
        while(m[minn])minn++;
        return ans;
    }
    
    void addBack(int num) {
        m[num] = 0;
        minn = min(minn, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */