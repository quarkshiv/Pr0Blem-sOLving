class Solution {
public:
   bool isprime(int n){
      if(n<=1)return false;
      if(n==2)return true;
      if(n%2==0)return false;
      for(int i=3;i*i<=n;i+=2){
             if(n%i==0)return false;
      }
      return true;
   }
 int cntprimes(int l,int r){
    int ans=0;
       for(int i=l;i<=r;i++){
             if(isprime(i))ans+=i;
       }
       return ans;
 }
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.size() && s[i]=='0')i++;
        s= s.substr(i);
         int r = stoi(s);
        return cntprimes(min(n,r),max(n,r));
    }
};