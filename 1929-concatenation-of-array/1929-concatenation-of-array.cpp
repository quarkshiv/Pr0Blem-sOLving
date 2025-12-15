class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*n);
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[i];
        }
        for(int i=n;i<ans.size();i++){
            ans[i]= nums[i-n];
        }
        return ans;
    }
};