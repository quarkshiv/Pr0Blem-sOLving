class Solution {
public:
void f(int ind,string s,vector<string>&ans,vector<vector<string>>&f_ans){
           if(ind==s.size()){
                f_ans.push_back(ans);
                return;
           }
           for(int i=ind;i<s.size();i++){
           string v= s.substr(ind,i-ind+1);
             
            if(ispal(v)){    
                ans.push_back(v);  
                f(i+1,s,ans,f_ans); 
                  ans.pop_back();
               }
             
           }
}
bool ispal(string s){
       int l=0;
       int h=s.size()-1;
       while(l<=h){
             if(s[l]!=s[h])return false;
             l++;
             h--;
       }
       return true;
}
    vector<vector<string>> partition(string s) {
          vector<vector<string>>f_ans;
          vector<string>ans;
          f(0,s,ans,f_ans);
          return f_ans;
    }
};