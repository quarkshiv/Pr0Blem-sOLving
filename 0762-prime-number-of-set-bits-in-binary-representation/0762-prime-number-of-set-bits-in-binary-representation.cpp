class Solution {
public:
   bool isprime(int n){
      if(n<=1){
        return false;
      }
      if(n==2){
        return true;
      }
      if(n%2==0)return false;
      for(int i=3;i<n;i++){
           if(n%i==0)return false;
      }
      return true;
   }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
               int cnt = __builtin_popcount(i);
               if(isprime(cnt)) ans++;
        }
        return ans;
    }
};