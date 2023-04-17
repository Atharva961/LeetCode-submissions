class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int maxx = 0;
        for(int i:candies)maxx = max(maxx, i);
        vector<bool> ans;
        for(int i:candies)
        {
            if(i+extra>=maxx)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};