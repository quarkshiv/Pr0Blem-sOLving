class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen=0;
        for(int i=0;i<nums.size();i++){
              unordered_set<int>odd,even;
              for(int j=i;j<nums.size();j++){
                    if(nums[j]%2)odd.insert(nums[j]);
                    else even.insert(nums[j]);
                    if(odd.size()==even.size()){
                            maxlen =max(maxlen,j-i+1);
                    }
              }
        }
        return maxlen;
    }
};