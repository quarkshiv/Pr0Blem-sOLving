class Solution {
public:
    vector<int> f(string s){
           vector<int>lps(s.size(),0);
           int len=0;
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
           else i++;
    }
    return lps;
    }
      bool kmp(string a,string b){
             int i=0;
             int j=0;
             vector<int>lps =f(b);
             while(i<a.size()){
                if(a[i]==b[j]){
                    j++;
                    i++;
                    if(j==b.size())return true;
                }
                else if(j!=0){
                    j= lps[j-1];
                }
                else i++;
             }
             return false;
      }
    int repeatedStringMatch(string a, string b) {
        string temp="";
        int cnt=0;
           while(temp.size()<b.size()){
            temp+=a;
            cnt++;
           }
           if(kmp(temp,b))return cnt;
           temp+=a;
           if(kmp(temp,b))return cnt+1;
           return -1;
    }
};