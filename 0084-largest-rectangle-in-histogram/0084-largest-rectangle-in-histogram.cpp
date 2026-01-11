class Solution {
public:
   void findnse(vector<int>& heights,vector<int>&nse){
            stack<int>st;
         for(int i=heights.size()-1;i>=0;i--){
               while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
               }
               if(st.empty()){
                   nse[i]=heights.size();
               }
               else nse[i]=st.top();
               st.push(i);
         }
   }
   void findpse(vector<int>& heights,vector<int>&pse){
      stack<int>st;
         for(int i=0;i<heights.size();i++){
             while(!st.empty() && heights[st.top()]>=heights[i]){
                          st.pop();
             }
             if(st.empty()){
                pse[i] =-1;
             }
             else pse[i]=st.top();
             st.push(i);
         }
   }
    int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();
        vector<int> nse(n), pse(n);
        findnse(heights,nse);
        findpse(heights,pse);
        int maxarea=0;
        for(int i=0;i<heights.size();i++){
              maxarea=max(maxarea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxarea;
    }
};