class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char  c: num){
              while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
              }
             st.push(c);
        }
        while(!st.empty() && k>0){
               st.pop();
               k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int ind =0;
         while(ind<ans.size() && ans[ind]=='0')ind++;
         ans = ans.substr(ind);
        return ans.empty() ? "0" : ans;
    }
};