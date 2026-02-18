class Solution {
public:
   string to_binary(int n){
       string s="";
        while(n>0){
              s+=char('0'+(n%2));
              n=n/2;
        }
        return s;
   }
    bool hasAlternatingBits(int n) {
        string s = to_binary(n);
           for(int i=1;i<s.size();i++){
                 if(s[i]==s[i-1]) return false;
           }
           return true;
    }
};