class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        while(mpp.find(original)!=mpp.end()){
            int x = 2 * original;
            original=x;
        }
       return original;
    }
};