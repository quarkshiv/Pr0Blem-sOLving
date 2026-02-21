class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int l=0;
        int maxlen =0;
         for(int r=0;r<s.size();r++){
              mpp[s[r]]++;
              while(mpp[s[r]]>1){
                    mpp[s[l]]--;
                   if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                   }
                    l++;
              }
              maxlen= max(maxlen,r-l+1);
         }
         return maxlen;
    }
};