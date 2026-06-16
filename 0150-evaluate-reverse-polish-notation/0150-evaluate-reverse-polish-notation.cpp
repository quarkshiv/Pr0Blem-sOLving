class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it : tokens){
             if(it=="/" || it=="+" || it=="*" || it=="-"){
                  int x = st.top();
                  st.pop();
                  int y = st.top();
                  st.pop();
                  int val;
                if (it == "+") val = y + x;
                else if (it == "-") val = y - x;
                else if (it == "*") val = y * x;
                else val = y / x;
                st.push(val);
             }
             else st.push(stoi(it));
        }
        return st.top();
    }
};