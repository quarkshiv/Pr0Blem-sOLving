class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c :s){
           if(c =='(' || c=='{' || c=='['){
            st.push(c);
           }
           else{
            if(st.size()==0){
                return 0;
            }
            char top = st.top();
            st.pop();
            if((top=='(' && c==')') || (top=='{' && c=='}') || (top=='[' && c==']')){
                continue;
            }
            else return false;
           }
         
        }
        return st.empty();
    }
};