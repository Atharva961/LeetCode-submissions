class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0, ones = 0;
        
        for(auto i:s)
        {
            if(i=='1')ones++;
            else flips++;
            
            flips = min(flips, ones);
        }
        
        return flips;
    }
};