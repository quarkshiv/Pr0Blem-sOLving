class Solution {
public:
   void findnse(vector<int>&r,vector<int>&nse){
        stack<int>st;
        for(int i=r.size()-1;i>=0;i--){
               while(!st.empty() && r[st.top()]>=r[i]) st.pop();
               nse[i]= st.empty() ? r.size():st.top();
               st.push(i);
        }
   }
   void findpse(vector<int>&r,vector<int>&pse){
        stack<int>st;
        for(int i=0;i<r.size();i++){
               while(!st.empty() && r[st.top()]>=r[i]) st.pop();
               pse[i]= st.empty() ? -1:st.top();
               st.push(i);
        }
   }
   int lhist(vector<int>& r){
           int area=0;
           int n =r.size();
           vector<int>nse(n);
           vector<int>pse(n);
           findnse(r,nse);
           findpse(r,pse);
           for(int i=0;i<r.size();i++){
                 area=max(area,r[i]*(nse[i]-pse[i]-1));
           }
           return area;
   }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
       if(matrix.empty() || matrix[0].empty())return 0;
          vector<vector<int>>ps(n,vector<int>(m,0)); 
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
               ps[i][j]= (i==0) ? 1 : ps[i-1][j]+1;
            else{
                ps[i][j]=0;
            }
          }
          }
          int maxarea=0;
        for(int i=0;i<n;i++){
              maxarea=max(maxarea,lhist(ps[i]));
        }
        return maxarea;
    }
};