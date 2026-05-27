class Solution {
public:
  bool up(char c){
    return c>='A' && c<='Z';
  }
  bool low(char c){
    return c>='a' && c<='z';
  }
bool dig(char c){
    return c>='0' && c<='9';
}
bool sp(char c){
    return c=='!' || c=='@' || c=='#' || c=='$';
}
    int passwordStrength(string password) {
        set<char>st;
        int ans=0;
        for(auto it : password){
             if(!st.contains(it)){
                   if(low(it))ans+=1;
                  else if(up(it))ans+=2;
                  else if(dig(it))ans+=3;
                  else if(sp(it))ans+=5;

             }
             st.insert(it);
        }
        return ans;
    }
};