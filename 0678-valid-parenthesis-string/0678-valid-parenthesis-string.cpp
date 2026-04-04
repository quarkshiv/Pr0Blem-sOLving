class Solution {
public:
    bool checkValidString(string s) {
        int maxi=0;
        int mini=0;
        for(auto it : s){
              if(it=='('){
                    maxi++;
                    mini++;
              }
              if(it==')'){
                   mini--;
                   maxi--;
              }
              if(it=='*'){
                   mini--;
                   maxi++;
              }
              if(mini<0){
                mini=0;
              }
              if(maxi<mini)return false;
        }
        return mini==0;
    }
};