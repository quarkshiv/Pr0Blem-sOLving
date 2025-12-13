class Solution {
public:
   void f(int num,int k,vector<int>&ans,int left){
        if(left==0){
         ans.push_back(num);
         return;
        }
        int last = num%10;
        int x1 = last -k;
        int x2 = last+k;
        if(x1>=0 && x1<=9){
             f(num*10 + x1,k,ans,left-1);
        }
        if(k!=0 && x2>=0 && x2<=9){
             f(num*10 + x2,k,ans,left-1);
        }
   }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            f(i,k,ans,n-1);
        }
       return ans;
    }
};