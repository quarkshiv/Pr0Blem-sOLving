class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int minop=0;
        while(target>startValue){
            if(target%2){
                target++;
                minop++;
            }
            else{
                target/=2;
                minop++;
            }
            
        }
        return minop + startValue-target;
    }
};