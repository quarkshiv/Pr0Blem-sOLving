class Solution {
public:
   int start=0;
   int maxlen=1;
       void expand(int l,int r,string s){
            while(l>=0 && r<s.size() && s[l]==s[r]){
                   if(r-l+1>maxlen){
                          start=l;
                          maxlen=r-l+1;
                   }
                   l--;
                   r++;
            }
       }
    string longestPalindrome(string s) {
        for(int i=0;i<s.size();i++){
              expand(i,i,s);
              expand(i,i+1,s);
        }
        return s.substr(start,maxlen);
    }
};