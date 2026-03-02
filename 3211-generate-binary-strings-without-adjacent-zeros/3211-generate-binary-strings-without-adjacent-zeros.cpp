class Solution {
public:
    void f(int ind,char prev,int n,string res,vector<string>& ans){
          if(ind==n){
               ans.push_back(res);
               return;
          }
            if(prev=='-1'|| prev=='1'){
                res+='0';
                f(ind+1,'0',n,res,ans);
                res.pop_back();
                res+='1';
                f(ind+1,'1',n,res,ans);
                res.pop_back();
            }
            else{
                   res+='1';
                   f(ind+1,'1',n,res,ans);
                   res.pop_back();
            }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string res="";
        f(0,'-1',n,res,ans);
        return ans;
    }
};