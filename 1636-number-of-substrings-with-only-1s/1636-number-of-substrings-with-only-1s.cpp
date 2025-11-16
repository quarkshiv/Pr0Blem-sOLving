class Solution {
public:
const int MOD=1e9 +7;
    int numSub(string s) {
        long long ans=0;
        long long cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }
            else{
                ans = ans + (cnt*(cnt+1)/2 % MOD) %MOD;
                cnt=0;
            }
        }
        ans = ans + (cnt*(cnt+1)/2 % MOD) %MOD;
        return ans;
    }
};