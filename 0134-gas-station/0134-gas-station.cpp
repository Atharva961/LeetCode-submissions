class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& costs) {
        int n = gas.size();
        int ans = 0;
        int cost = 0;
        int total = 0;
        
        for(int i=0; i<n; i++)
        {
            total+=(gas[i]-costs[i]);
            cost+=(gas[i]-costs[i]);
            
            if(cost<0)
            {
                cost = 0;
                ans = i+1;
            }
        }
        
        if(total<0)return -1;
        return ans;
    }
};