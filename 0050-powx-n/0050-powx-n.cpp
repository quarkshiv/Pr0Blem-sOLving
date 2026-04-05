class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }  
        if(n<0){
              x=1/x;
               if(x==INT_MIN){
                return x * myPow(x,INT_MAX);
               }
              n=-n;
        }
        double half = myPow(x,n/2);  
        if(n%2){
               return half*half*x;
        }   
        else return half*half;       
    }
};