class Solution {
public:
    int bestClosingTime(string s) {
        int n= s.size();
        vector<int>pref(n+1,0),suff(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1] + (s[i-1]=='N');
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1] + (s[i]=='Y');
        }
        int mini=INT_MAX;
        int time=0;
        for(int i=0;i<=n;i++){
            int val = pref[i]+suff[i];
            if(mini>val){mini=val;
            time=i;}
        }
        return time;
            }
};