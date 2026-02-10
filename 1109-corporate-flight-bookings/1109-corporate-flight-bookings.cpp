class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(auto it : bookings){
              int u = it[0];
              int v = it[1];
              int val = it[2];
             for(int i=u;i<=v;i++){
                ans[i-1]+=val;
             }

        }
        return ans;
    }
};