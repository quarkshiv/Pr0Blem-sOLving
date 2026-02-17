class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int hour=0;hour<=11;hour++){
             for(int min=0;min<=59;min++){
                   if(__builtin_popcount(hour)+ __builtin_popcount(min)==turnedOn){
                            string time = to_string(hour) + ":";
                            if(min<10){
                                  time+="0";
                            }
                            time+=to_string(min);
                            ans.push_back(time);
                   }
             }
        }
        return ans;
    }
};