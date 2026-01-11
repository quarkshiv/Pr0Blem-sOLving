class Solution {
public:

 const int MOD = 1e9 + 7;
 vector<int> findpse(vector<int>& arr){
     int n =arr.size();
    vector<int>ans(n);
    stack<int>st;
   
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        ans[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
 }
 vector<int> findnse(vector<int>& arr){
        int n =arr.size();
    vector<int>ans(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
 }
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
      vector<int>nse= findnse(arr);
      vector<int>pse=findpse(arr);
      int total=0;
      for(int i=0;i<n;i++){
        int right=nse[i]-i;
        int left=i-pse[i];
        total=((total+ (left*right *1ll * arr[i])% MOD)%MOD);
      }
      return total;
        }
    
    
};