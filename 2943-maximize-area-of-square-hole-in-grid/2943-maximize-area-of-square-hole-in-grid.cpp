class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int size=vBars.size();
        int sizeh=hBars.size();
        int currh=1;
        int ansh=1;
        int currv=1;
        int ansv=1;
        for(int i=1;i<sizeh;i++){
                if(hBars[i]==hBars[i-1]+1) currh++;
                else{
                      currh=1;
                }
                ansh= max(ansh,currh);
        }
        for(int i=1;i<size;i++){
                if(vBars[i]==vBars[i-1]+1) currv++;
                else{
                      currv=1;
                }
                 ansv = max(ansv,currv);
        }

        int side = min(ansh,ansv)+1;
        return side*side;
    }
};