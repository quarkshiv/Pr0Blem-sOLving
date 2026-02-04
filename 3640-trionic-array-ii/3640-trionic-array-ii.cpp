class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<long long> incEnd(n, -1e18);
        vector<long long> incStart(n, -1e18);
        long long ans = -1e18;
        for (int i = 0; i < n; i++) {
            incEnd[i] = nums[i];
            if (i && nums[i] > nums[i - 1]) {
                incEnd[i] = max((long long)nums[i - 1] + nums[i],
                                incEnd[i - 1] + nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            incStart[i] = nums[i];
            if (i < n - 1 && nums[i] < nums[i + 1]) {
                incStart[i] = max((long long)nums[i] + nums[i + 1],
                                  incStart[i + 1] + nums[i]);
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                int j = i;
                long long sum = 0;
                while (j < n - 1 && nums[j] > nums[j + 1]) {
                    sum += nums[j];
                    j++;
                }
                if (j < n - 1 && nums[j] < nums[j + 1]) {
                    ans = max(ans, incEnd[i] - nums[i] + sum + incStart[j]);
                }
                i = j;
            }
        }
        return ans;
    }
};