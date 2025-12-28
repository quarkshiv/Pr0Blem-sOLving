class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini = INT_MAX;
        int sump=0;
        int sumn=0;
        for(int i=0;i<nums.size();i++){
             sump+=nums[i];
             sumn+=nums[i];
                maxi=max(maxi,sump);
                mini = min(mini,sumn);
                if(sump<0){
                    sump=0;
                }
                if(sumn>0){
                    sumn=0;
                }
        }
        return max(abs(mini),maxi);
    }
};