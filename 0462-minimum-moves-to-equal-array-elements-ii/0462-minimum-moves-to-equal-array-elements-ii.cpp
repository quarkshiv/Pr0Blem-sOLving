class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int med=0;
        if(n%2!=0){
            med = nums[((n+1)/2)-1];
        }
        else{
            med = nums[(n/2)-1];
        }
        for(int i=0;i<nums.size();i++){
            ans+=abs(med-nums[i]);
        }
        return ans;
    }
};