class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int beg = 0, end = 0;
        map<int, int> m;
        
        while(end<fruits.size())
        {
            m[fruits[end]]++;
            while(m.size()>2 && beg<end) 
            {
                m[fruits[beg]]--;
                if(m[fruits[beg]]==0)
                {
                    m.erase(fruits[beg]);
                }
                beg++;
            }
            end++;
            ans = max(ans, end-beg);
        }
        
        return ans;
    }
};