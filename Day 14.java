// Angle Between Hands of a Clock

class Solution {
    public double angleClock(int hour, int minutes) {
        double hourAngle = hour * 30 + minutes * (0.5);
        double minuteAngle = minutes * 6;
        
        double diff = Math.abs(hourAngle - minuteAngle);
        
        return Math.min(diff, 360 - diff);
    }
}