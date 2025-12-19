class Solution {
public:
    const int mod = 1e9+7;
      int rev(int n){
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int ind=0;
        while(ind<s.size() && s[ind]=='0') ind++;
        if(ind==s.size())return 0;
        s = s.substr(ind,s.size());
        return stoi(s);
      }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = (nums[i] - rev(nums[i]));
        }
        map<int,int>mpp;
        for(int i=0;i<n;i++){
              mpp[nums[i]]++;
              }
       long long ans= 0; 
       for(auto it : mpp){
        ans=(ans +1LL*(it.second)*(it.second-1)/2)%mod;
       }
       return (int)ans;
    }
};