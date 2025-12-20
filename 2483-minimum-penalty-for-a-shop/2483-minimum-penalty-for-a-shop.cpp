class Solution {
public:
    int bestClosingTime(string s) {
         int n =s.size();
         vector<int>pref(n+1,0);
         vector<int>suff(n+1,0);
         int ans= INT_MAX;
         int time=0;
         for(int i=1;i<=n;i++){
            pref[i]+=(pref[i-1] + (s[i-1]=='N')); 
         }
         for(int i=n-1;i>=0;i--){
            suff[i]+=(suff[i+1] + (s[i]=='Y')); 
         }
        for(int i=0;i<=n;i++){
            int pre= pref[i];
            int suf = suff[i];
           if(ans>pre+suf){
            ans= pre+suf;
            time = i;
           }
        }
        return time;
    }
};