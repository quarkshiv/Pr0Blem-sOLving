class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it :mpp){
            if(it.second>1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};