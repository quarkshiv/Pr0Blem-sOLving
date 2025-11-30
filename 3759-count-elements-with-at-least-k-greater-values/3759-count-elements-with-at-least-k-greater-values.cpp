class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k==0){
            return nums.size();
        }
        int cnt=0;
        sort(nums.begin(),nums.end());
        int ind = nums.size()-k;
        int val = nums[val];
        for(int i=0;i<nums.size();i++){
               if(nums[i]>val){
                cnt++;
               }
        }
        return cnt;
    }
};
