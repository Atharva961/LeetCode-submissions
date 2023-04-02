class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> h(nums.size()+1, 0);
        for(int i:nums)h[i]++;
        vector<vector<int>> ans;
        while(true)
        {
            int count = 0;
            vector<int> temp;
            for(int i=0; i<h.size(); i++)
            {
                if(h[i])
                {
                    count++;
                    temp.push_back(i);
                    h[i]--;
                }
            }
            if(!count)break;
            ans.push_back(temp);
        }
        
        return ans;
    }
};