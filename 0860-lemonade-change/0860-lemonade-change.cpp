class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cfive=0;
        int cten=0;
           for(auto it : bills){
                if(it==5){
                      cfive++;
                }
                if(it==10){
                       if(cfive>0){
                        cfive--;
                        cten++;
                       }
                       else return false;
                }
                if(it==20){
                       if(cten>=1 && cfive>=1){
                            cfive--;
                            cten--;
                       }
                       else if(cfive>=3){
                           cfive-=3;
                      }
                       else return false;
                }
           }
           return true;
    }
};