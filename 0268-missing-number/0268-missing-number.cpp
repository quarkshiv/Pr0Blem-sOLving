class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
             if(!mpp.count(i)){
                   return i;
             }
        }
        int maxi = *max_element(nums.begin(),nums.end());
        return maxi+1;
    }
};