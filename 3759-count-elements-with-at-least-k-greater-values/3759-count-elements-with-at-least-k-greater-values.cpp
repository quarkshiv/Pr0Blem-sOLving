class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k==0){
            return nums.size();
        }
        int cnt=0;
        sort(nums.begin(),nums.end());
        int ind = nums.size()-k;
        if (ind < 0 || ind >= nums.size()) return 0; 
        int val = nums[ind];
        for(int i=0;i<nums.size();i++){
               if(nums[i]<val){
                cnt++;
               }
        }
        return cnt;
    }
};
