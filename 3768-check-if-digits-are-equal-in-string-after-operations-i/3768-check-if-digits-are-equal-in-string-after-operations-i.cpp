class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()!=2){
            string temp ="";
            for(int i=1;i<s.size();i++){
                    temp+= ((s[i]+s[i-1]) %10);
            }
            s = temp;
        }
        if(s[0]==s[1]){
            return true;
        }
        else return false;
    }
};