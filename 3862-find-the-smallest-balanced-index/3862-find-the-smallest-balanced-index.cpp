class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pref(n+1,0);
        vector<long long> suff(n+1,1);

        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + nums[i-1];
        }
        long long limit = pref[n];
        for(int i=n-1;i>=0;i--){
            if(suff[i+1] > limit / max(1LL,(long long)nums[i]))
                suff[i] = limit + 1;   
                else
            suff[i] = suff[i+1] * nums[i];
        }

        for(int i=0;i<n;i++){
            if(pref[i] == suff[i+1]) return i;
        }

        return -1;
    }
};