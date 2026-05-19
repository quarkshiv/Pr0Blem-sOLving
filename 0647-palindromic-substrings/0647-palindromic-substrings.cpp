class Solution {
public:
int cnt=0;
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
              f(i,i,s);
              f(i,i+1,s);
        }
        return cnt;
    }
    void f(int l,int r,string s){
          while(l>=0 && r<s.size() && s[l]==s[r]){cnt++;
          l--;
          r++;
    }
    }
};