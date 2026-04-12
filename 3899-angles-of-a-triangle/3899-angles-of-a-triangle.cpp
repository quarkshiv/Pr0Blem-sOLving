class Solution {
public:
   bool check(vector<int> &sides){
    sort(sides.begin(), sides.end());
    if(sides[2] >= sides[0] + sides[1]) return false;
    else return true;
   }

    vector<double> internalAngles(vector<int>& s) {
       if(!check(s)) return {};

        vector<double> ans(3);
        const double PI = acos(-1);
        double x = (1.0*s[1]*s[1] + 1.0*s[2]*s[2] - 1.0*s[0]*s[0]) / (2.0*s[1]*s[2]);
        x = max(-1.0, min(1.0, x));
        ans[0] = acos(x) * 180.0 / PI;
        double y = (1.0*s[2]*s[2] + 1.0*s[0]*s[0] - 1.0*s[1]*s[1]) / (2.0*s[0]*s[2]);
        y = max(-1.0, min(1.0, y));
        ans[1] = acos(y) * 180.0 / PI;

        ans[2] = 180.0 - ans[1] - ans[0];

        return ans;
    }
};