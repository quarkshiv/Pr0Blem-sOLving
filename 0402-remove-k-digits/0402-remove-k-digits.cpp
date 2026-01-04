class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char c : num){
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
                   char top = st.top();
                   st.pop();
                   ans+=top;
        }
        reverse(ans.begin(),ans.end());
        int ind=0;
        while(ind<ans.size() && ans[ind]=='0') ind++;
        ans= ans.substr(ind);
        if(ans.empty()) return "0";
        else return ans;
    }
};