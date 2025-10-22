class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> v;
        int maxi = *max_element(nums.begin(), nums.end()); 
        for (int i = 1; i * k <= maxi + k; i++) {
            v.push_back(i * k);
        }
        for (int i = 0; i < v.size(); i++) {
            bool valid = false;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == v[i]) {
                    valid = true;
                    break;
                }
            }
            if (!valid) {
                return v[i]; 
            }
        }
        return (v.back() + k);
    }
};
