class KthLargest {
public:
    vector<int> v;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        v = nums;
        sort(v.begin(), v.end());
    }
    
    int add(int val) {
        int idx = upper_bound(v.begin(), v.end(), val) - v.begin();
        v.insert(v.begin()+idx, val);
        return v[v.size()-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */