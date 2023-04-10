class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, long long> count, sum;
        vector<long long> ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
            sum[nums[i]]+=i;
            long long a = count[nums[i]]*i;
            long long b = sum[nums[i]];
            ans[i] += (a-b);
        }
        count.clear();
        sum.clear();
        for(int i=nums.size()-1; i>=0; i--)
        {
            count[nums[i]]++;
            sum[nums[i]]+=i;
            long long a = count[nums[i]]*i;
            long long b = sum[nums[i]];
            ans[i] += (b-a);
        }
        return ans;
    }
};