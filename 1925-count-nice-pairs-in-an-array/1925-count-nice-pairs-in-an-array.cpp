class Solution {
public:
     int rev(int n){
         int rev=0;
         while(n!=0){
            int dig =n%10;
            rev=(rev*10) + dig;
            n=n/10;
         }
         string s=to_string(rev);
         int i=0;
         while(i<s.size() && s[i]=='0'){
            i++;
         }
          if (i == s.size()) return 0;
         string res = s.substr(i,s.size());
         return stoi(res);
     }

    int countNicePairs(vector<int>& nums) {
       const int MOD = 1e9 + 7;

       for(int i=0;i<nums.size();i++){
           nums[i]=(nums[i]-rev(nums[i]));
       }

       unordered_map<int,int>mpp;
       for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
       }

       long long cnt=0;

       for(auto it : mpp){
          long long freq = it.second;
          cnt = (cnt + (freq * (freq - 1) / 2) % MOD) % MOD; 
       }

       return cnt % MOD;
    }
};
