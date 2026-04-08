class Solution {
public:
        void f(int open,int close,int n,string path,vector<string>& ans){
               if(close==n){
                   ans.push_back(path);
                   return;
               }
               if(open<n){
                    f(open+1,close,n,path+'(',ans);
               }
               if(close<open){
                    f(open,close+1,n,path +')',ans);
               }
        }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string path;
        f(0,0,n,path,ans);
        return ans;
    }
};