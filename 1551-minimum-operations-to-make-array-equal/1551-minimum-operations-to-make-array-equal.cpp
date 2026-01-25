class Solution {
public:
    int minOperations(int n) {
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=2*i +1;
        }
        int med;
        if(n%2){
            med=arr[n/2];
        }
        else med= (arr[n/2-1] + arr[((n)/2 +1)-1])/2;
        int op=0;
        int i=0;
        int j=n-1;
        for(int i=0;i<n;i++){
            if(arr[i]>=med){
                break;
            }
            op+=med-arr[i];
        }
        return op;
    }
};