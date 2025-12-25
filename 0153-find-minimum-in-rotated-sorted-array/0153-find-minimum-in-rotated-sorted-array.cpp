class Solution {
public:
int findRotationIndexLinear(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            return i;
        }
    }
    return 0;
}
    int findMin(vector<int>& nums) {
     int k = findRotationIndexLinear(nums);
     k=k%nums.size();
     reverse(nums.begin() + k, nums.end());
     reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin(), nums.end());
    
    return nums[0];
    }

};