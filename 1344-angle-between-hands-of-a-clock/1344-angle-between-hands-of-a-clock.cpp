class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_angle = minutes*6.00000;
        double hour_angle;
        if(hour==12)hour_angle = 0;
        else hour_angle = hour*30.00000;
        
        double hour_deviation = minute_angle/12.00000;
        hour_angle+=hour_deviation;
        
        double ans = abs(minute_angle-hour_angle);
        
        if(ans>180)return 360-ans;
        
        return ans;
    }
};