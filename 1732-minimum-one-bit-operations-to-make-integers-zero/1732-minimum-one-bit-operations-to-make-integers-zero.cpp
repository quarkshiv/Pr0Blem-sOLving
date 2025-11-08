class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;

    int k = 63 - __builtin_clzll(n);
    int p = 1LL << k;                     

    if(n == p){
        return (1LL << (k+1)) - 1;
    }
    int x = n - p;
    return ( (1LL << (k+1)) - 1 ) -  minimumOneBitOperations(x);
}
};