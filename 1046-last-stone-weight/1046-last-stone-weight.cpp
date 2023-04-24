class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i:stones)q.push(i);
        while(q.size())
        {
            int y = q.top();
            q.pop();
            if(q.empty())return y;
            int x = q.top();
            q.pop();
            if(y-x>0)q.push(y-x);
        }
        return 0;
    }
};