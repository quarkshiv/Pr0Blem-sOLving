class Solution {
public:
    double angleClock(int hour, int minutes) {
        double  mind = (double)minutes/5.0;
        cout<<mind<<endl;
        double h = (double)hour + minutes/60.0;
        cout<<h<<endl;
        double ans=0.0;
              ans = abs (h-mind)*30;
              return min(ans,360-ans);
    }
};