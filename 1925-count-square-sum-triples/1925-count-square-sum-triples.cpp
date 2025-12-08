class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                 int c= (i*i)+(j*j);
                 int sc = sqrt(c);
                 if(sc<=n && sc*sc==c) cnt++;
                }
            }
        return cnt;
    }
};