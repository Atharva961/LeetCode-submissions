class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        vector<vector<int>> v;
        for (int i = 0; i < reward1.size(); i++)
        {
            v.push_back({reward1[i] - reward2[i], reward1[i], reward2[i]});
        }
        sort(v.begin(), v.end(), compare);
        int ans = 0;
        int i = 0;
        while (k > 0)
        {
            ans += v[i][1];
            i++;
            k--;
        }
        for (; i < v.size(); i++)
            ans += v[i][2];

        return ans;
    }
};