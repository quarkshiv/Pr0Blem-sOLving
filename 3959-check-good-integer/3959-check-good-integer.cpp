class Solution {
public:
     int square(int n){
          int sum= 0;
          while(n>0){
               int dig = n%10;
               sum+=dig*dig;
               n/=10;
          }
          return sum;
     }
     int digsum(int n){
          int sum= 0;
          while(n>0){
               int dig = n%10;
               sum+=dig;
               n/=10;
          }
          return sum;
     }
    bool checkGoodInteger(int n) {
        int sq = square(n);
      int dig=digsum(n);
      return sq-dig>=50;
    }
};