class Solution {
public:
   bool upp(char c){
    return c>='A' && c<='Z';
   }
   bool small(char c){
    return c>='a' && c<='z';
   }
    int numberOfSpecialChars(string word) {
        set<char>st;
        set<char>vis;
        int ans=0;
        for(auto it : word){
             if(small(it)){
                   st.insert(it);
             }
        }
        for(auto it : word){
              if(upp(it) && st.contains(tolower(it)) && !vis.contains(tolower(it))){
                     ans++;
                     vis.insert(tolower(it));
               }
        }
        return ans;
    }
};