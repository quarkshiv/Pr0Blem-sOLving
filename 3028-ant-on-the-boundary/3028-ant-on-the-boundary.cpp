class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int pos=0;
        int cnt=0;
        for(auto it : nums){
               pos+=it;
               if(pos==0)cnt++;
        }
        return cnt;
    }
};