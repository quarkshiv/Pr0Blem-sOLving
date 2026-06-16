class Solution {
public:
    string processStr(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(islower(s[i])){
                res+=s[i];
            }
           else if(s[i]=='*' && res.size()>=1){
                res.erase(res.size()-1);
            }
            else if(s[i]=='#'){
                res= res +res;
            }
            else{
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};