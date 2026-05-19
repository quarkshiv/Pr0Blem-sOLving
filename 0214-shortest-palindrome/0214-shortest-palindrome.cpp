class Solution {
public:
  vector<int>f(string s){
    int n =s.size();
    vector<int>lps(n,0);
       int len = 0;
       int i=1;
       while(i<s.size()){
           if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
           }
           else if(len!=0){
               len = lps[len-1];
           }
           else{
            lps[i]=0;
             i++;
           }
       }
       return lps;
  }
    string shortestPalindrome(string s) {
        string temp = s;
        reverse(s.begin(),s.end());
        temp= temp +"#"+ s;
        vector<int>lps = f(temp);
        int len = lps.back();
        reverse(s.begin(),s.end());
        string pal = s.substr(len);
        reverse(pal.begin(),pal.end());
         
        return pal+s;
    }
};