class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int idx = n - k;
        if (idx < 0 || idx >= n) return 0; 
        int t= nums[idx];
        int cnt = 0;
        for(int x : nums){
            if(x < t) cnt++;
        }

        return cnt;
    }
};
