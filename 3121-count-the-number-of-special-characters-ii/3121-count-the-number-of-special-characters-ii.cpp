class Solution {
public:
   bool upp(char c){
    return c>='A' && c<='Z';
   }
   bool small(char c){
    return c>='a' && c<='z';
   }
    int numberOfSpecialChars(string word) {
      unordered_map<char,int>up;
    unordered_map<char,int>low;
    for(int i=0;i<word.size();i++){
          if(small(word[i])){
               low[word[i]]=i;
          }
          else if(upp(word[i]) && !up.count(word[i])){
               up[word[i]]=i;
          }
    }
    int ans=0;
    for(auto it : low){
          if(up.count(toupper(it.first)) && up[toupper(it.first)]>it.second)ans++;
    }

       return ans;
    }
};