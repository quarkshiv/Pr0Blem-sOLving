class Solution {
public:
    int maxProduct(vector<string>& nums) {
        int len=0;
        for(int i=0;i<nums.size();i++){
               unordered_map<char,int>mpp;
                 for(auto it : nums[i]){
                      mpp[it]++;
                 }
               
              for(int j=i+1;j<nums.size();j++){
                  bool valid = true;
                     for(auto c : nums[j]){
                   if(mpp.find(c)!=mpp.end()){
                         valid=false;
                         break;
                   }
                     }
                   if(valid){
                       len = max(len,int(nums[i].size() * nums[j].size()));
                   }
              }
        }
        return len;
    }
};