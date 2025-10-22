class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> v;
        int maxi = *max_element(nums.begin(), nums.end()); // fixed *

        // store all multiples of k up to maxi + k
        for (int i = 1; i * k <= maxi + k; i++) {
            v.push_back(i * k);
        }

        // brute force: find first multiple not in nums
        for (int i = 0; i < v.size(); i++) {
            bool valid = false;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == v[i]) {
                    valid = true;
                    break;
                }
            }
            if (!valid) {
                return v[i]; // first missing multiple
            }
        }

        // if none missing, return next multiple
        return (v.back() + k);
    }
};
