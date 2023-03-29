class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        
        vector<int> curr(n+1, 0), next(n+1, 0);
        
        for(int i=n-1; i>=0; i--)
        {
            for(int time = i; time>=0; time--)
            {
                int include = satisfaction[i] * (time+1) + next[time+1];
                int exclude = next[time];
                
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        
        return next[0];
    }
};