class Solution {
public:
  bool isbinarypalindrome(int x){
    string s="";
         while(x>0){
            s+= char((x%2)+'0');
            x=x/2;
         }
         string rev=s;
         reverse(s.begin(),s.end());
         return rev==s;
  }
int nearestbinarybefore(int n){
    int cnt=0;
    bool valid= false;
      for(int i=n;i>=0;i--){
            if(isbinarypalindrome(i)){
                valid=true;
                return cnt;
            }
             cnt++;
      }
      if(!valid){
           return INT_MAX;
      }
      else return cnt;

}
int nearestbinaryafter(int n){
    int cnt=0;
    bool valid= false;
      for(int i=n;i<=5000;i++){
            if(isbinarypalindrome(i)){
                valid=true;
                return cnt;
            }
            cnt++;
      }
      if(!valid){
           return INT_MAX;
      }
      else return cnt;
}
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<nums.size();i++){
            int cnt=0;
           int cnt1= nearestbinaryafter(nums[i]);
            int cnt2=nearestbinarybefore(nums[i]);
            cnt = min(cnt1,cnt2);
            ans[i]=cnt;
        }
       return ans;
    }
};