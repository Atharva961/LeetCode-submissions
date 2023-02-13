class Solution {
public:
    int odds(int num)
    {
        if(num==1)return 1;
        if(num%2!=0)return num/2+1;
        return num/2;
    }
    int countOdds(int low, int high) {
        if(low==0)return odds(high);
        int n1 = odds(low-1);
        int n2 = odds(high);
        return n2-n1;
    }
};