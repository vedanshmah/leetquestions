class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourno=0.0;
        double angle=0.0;
        
        hourno=((hour%12)*5) + (minutes/12.0);
        angle=abs(hourno-minutes)*6;
        if(angle>180){
            angle=360-angle;
        }
        return angle;;
        
    }
};