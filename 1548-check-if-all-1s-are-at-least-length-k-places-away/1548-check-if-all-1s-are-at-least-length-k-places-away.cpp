class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        for(int v=0;v<nums.size();v++){
            if(nums[v]==1){
                 i =v;
                break;
            }
        }
        j=i+1;
        while(j<nums.size()){
            if(nums[j]==1){
                if((j-i-1)<k){
                    return false;
                }
                i=j;
                j=i+1;
            }
             else j++;
        }
        return true;
    }
};