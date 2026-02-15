class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        int i = l;
        int j = mid + 1;
        int k = 0;
        vector<int> ans(r - l + 1);

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                ans[k++] = nums[i++];
            } else {
                ans[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            ans[k++] = nums[i++];
        }
        while (j <= r) {
            ans[k++] = nums[j++];
        }
        for (int m = 0; m < ans.size(); ++m) {
            nums[l + m] = ans[m];
        }
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
