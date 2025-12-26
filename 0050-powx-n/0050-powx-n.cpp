class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            x=1/x;
            if(x==INT_MIN){
                return x * (x,INT_MAX);
            }
            n=-n;
        }
          double half= myPow(x,n/2);
          if(n%2){
                return x*half*half;
          }
          else return half*half;
    }
};