class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
                   return 0;
        }
        sort(nums.begin(),nums.end());
        int cnt=1;
        int maxcount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    cnt++;
                }
            else{
            maxcount = max(maxcount,cnt);
            cnt=1;
        }
        }
        }
        return max(cnt,maxcount);
    }
};