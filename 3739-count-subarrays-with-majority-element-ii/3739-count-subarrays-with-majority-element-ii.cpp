class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp; //cumSum -> Count

        int cumsum=0;
        mp[0] = 1;

        long long validlp= 0;
        long long res=0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == target) {
                validlp+= mp[cumsum];
                cumsum++;
            } else {
                cumsum--;
                validlp-=mp[cumsum];
            }
            mp[cumsum]++;
            res += validlp;
        }
        return res;
    }
};