class Solution {
public:
      void generate(int ind,int k,string  & s,vector<string>&ans){
          if(ind==k){
               ans.push_back(s);
               return;
          }
          s.push_back('0');
          generate(ind+1,k,s,ans);
          s.pop_back();
           s.push_back('1');
          generate(ind+1,k,s,ans);
          s.pop_back();
      }
    string findDifferentBinaryString(vector<string>& nums) {
        int k = nums[0].size();
        string s="";
        vector<string>ans;
        generate(0,k,s,ans);
        sort(ans.begin(),ans.end());
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size() && ans[i]==nums[i]){
            i++;
        }
        return ans[i];
    }
};