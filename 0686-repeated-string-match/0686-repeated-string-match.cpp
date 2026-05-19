class Solution {
public:
     bool rbk(string a,string b){
          int n  = a.size();
          int m = b.size();
          const int base=31;
          const int mod=1e9+7;
          long long power = 1;
          long long ptrhash=0;
          long long winhash=0;
          for(int i=0;i<m-1;i++){
                 power = (power*base)%mod;
          }
          for(int i=0;i<m;i++){
               ptrhash = (ptrhash*base + (b[i]-'a'+1))%mod;
               winhash = (winhash*base + (a[i]-'a'+1))%mod;
          }
          for(int i=0;i<=n-m;i++){
               if(ptrhash==winhash){
                    if(a.substr(i,m)==b)return true;
               }
               winhash= (winhash - (a[i]-'a'+1)*power%mod+mod)%mod;
               winhash = (winhash*base + (a[i+m]-'a'+1))%mod;
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
           if(rbk(temp,b))return cnt;
           temp+=a;
           if(rbk(temp,b))return cnt+1;
           return -1;
    }
};