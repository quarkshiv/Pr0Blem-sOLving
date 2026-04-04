class Solution {
public:
     void f(int ind,string s ,vector<vector<string>>&f_ans, vector<string>&ans){
             if(ind==s.size()){
                   f_ans.push_back(ans);
                   return;
             }
             for(int i=ind;i<s.size();i++){
                   if(ispal(s,ind,i)){
                       ans.push_back(s.substr(ind,i-ind+1));
                       f(i+1,s,f_ans,ans);
                       ans.pop_back();
                   }
             }
     }
bool ispal(string s, int l , int r){
    while(l<=r){
        if(s[l++]!=s[r--]) return false;
    }
    return true;
   }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>f_ans;
        vector<string>ans;
        f(0,s,f_ans,ans);
        return f_ans;
    }
};