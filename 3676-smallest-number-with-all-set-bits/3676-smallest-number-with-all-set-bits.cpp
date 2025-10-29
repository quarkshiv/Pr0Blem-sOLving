class Solution {
public:
    int smallestNumber(int n) {
       for(int i=n;i<=1e9;i++){
        int cnt=0;
        int set=0;
        int temp=i;
        while(temp){
             if(temp&1){
                set++;
             }
             cnt++;
             temp=temp/2;
        }
        if(cnt==set){
            return i;
        }
       }
       return 0;
    }
};