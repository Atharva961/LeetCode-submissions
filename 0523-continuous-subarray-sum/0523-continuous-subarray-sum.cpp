class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            int rem = sum%k;
            if(!(m.find(rem)!=m.end()))m[rem] = i;
            // printf("%d\t%d\t%d\t%d\n", i, sum, rem, m[rem]);
            if(rem==0 && i>0)return true;
            if(i-m[rem]>=2)return true;
        }
        return false;
    }
};