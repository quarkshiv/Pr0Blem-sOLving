class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>ms;
        int l=0;
        int ans=0;
        for(int r=0;r<nums.size();r++){
               ms.insert(nums[r]);
                while(*ms.rbegin()-*ms.begin()>limit){
                         ms.erase(ms.find(nums[l]));
                         l++;
                }
                ans = max(ans,r-l+1);
        }
        return ans;
    }
};