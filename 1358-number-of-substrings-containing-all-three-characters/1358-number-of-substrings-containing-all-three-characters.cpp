class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mpp;
        int ans=0;
        int n =s.size();
        long long tot = 1ll*n *(n+1)/2;
        int l=0;
        for(int r=0;r<s.size();r++){
               mpp[s[r]]++;
               while(mpp.size()>2){
                       mpp[s[l]]--;
                       if(mpp[s[l]]==0){
                            mpp.erase(s[l]);
                       }
                       l++;
               }
               ans+=(r-l+1);
        }
        return tot-ans;
    }
};