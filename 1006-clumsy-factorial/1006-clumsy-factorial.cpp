class Solution {
public:
    int clumsy(int n) {
        stack<int>st;
        st.push(n);
        n--;
        int parity=0;
        while(n>0){
             if(parity==0){
                int t = st.top();
                st.pop();
                st.push(t*n);
             }
             else if(parity==1){
                int t= st.top();
                st.pop();
                st.push(t/n);
             }
             else if(parity==2){
               st.push(n);
             }
             else{
                st.push(-n);
             }
             parity = (parity +1)%4;
             n--;
        }
        int res=0;
        while(!st.empty()){
               res+=st.top();
               st.pop();
        }
        return res;
    }
};