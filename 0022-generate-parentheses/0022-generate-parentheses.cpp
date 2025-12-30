class Solution {
public:
      void generate( vector<string>& res,string s,int open,int close,int n){
        if(s.length()==n*2) {res.push_back(s);
        return;
        }
       if(open<n){
        generate(res,s+"(",open+1,close,n);
       }
       if(close<open){
        generate(res,s+")",open,close+1,n);
       }

      }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate(res,"",0,0,n);
        return res;
        
        
    }
};