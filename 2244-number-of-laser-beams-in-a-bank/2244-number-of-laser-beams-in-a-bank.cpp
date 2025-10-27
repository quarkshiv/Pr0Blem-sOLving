class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int tot=0;
         int prevcnt=0;
       for(auto it :  bank){
        int currcnt=0;
        for(auto c : it){
            if(c=='1') currcnt++;
        }
            if(currcnt>0){
                tot+= prevcnt * currcnt;
                prevcnt = currcnt;
            }
        }
        return tot;

    }
};