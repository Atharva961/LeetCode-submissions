class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        
        priority_queue<int> q(nums.begin(), nums.end());
        
        while(k--)
        {
            long long t = q.top();
            q.pop();
            ans+=t;
            long long newVal = ceil(t/3.0);
            q.push(newVal);
        }
        
        return ans;
    }
};