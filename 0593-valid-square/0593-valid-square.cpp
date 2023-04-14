class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<double> s;
        
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3|| p2==p4 || p3==p4)return false;
        s.insert(dist(p1, p2));
        s.insert(dist(p1, p3));
        s.insert(dist(p1, p4));
        s.insert(dist(p2, p3));
        s.insert(dist(p2, p4));
        s.insert(dist(p3, p4));
        
        return s.size()==2;
    }
};