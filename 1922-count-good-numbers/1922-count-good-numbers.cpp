class Solution {
public:
static const long long MOD = 1000000007;
      long long pow(long long base, long long exp) {
       if(exp==0){
        return 1;
       }
       long long half = pow(base,exp/2);
       if(exp%2==0){
        return half *half %MOD;
       }
        return base * half * half %MOD;
       
      }
    int countGoodNumbers(long long n) {
        long long evenind=(n+1)/2;
        long long oddind=n/2;

        return pow(5,evenind) * pow(4,oddind) %MOD;

        
        
        
    }
};
