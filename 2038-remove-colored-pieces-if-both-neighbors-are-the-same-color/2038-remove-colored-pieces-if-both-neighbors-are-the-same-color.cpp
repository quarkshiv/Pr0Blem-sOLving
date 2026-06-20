class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A') cnt++;
             if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B') cnt--;
           
        }
     return cnt>0;
    }
};