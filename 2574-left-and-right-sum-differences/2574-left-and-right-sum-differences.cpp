class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>v;int y=0;
       int answer;
       int sum= accumulate(nums.begin(),nums.end(),0);
       for(int i=0;i<nums.size();i++){
          y+=nums[i];
          v.push_back(abs(sum-y));
          sum-=nums[i];
       }
       return v;
    }
};