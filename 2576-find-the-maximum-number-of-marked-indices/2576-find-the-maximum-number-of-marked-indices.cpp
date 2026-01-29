class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int ans=0;
        int i=0;
        int j=n/2;
        while(i<n/2 && j<n){
              if(2*nums[i]<=nums[j]){
                    ans+=2;
                    i++;
                    j++;
              }
              else{
                  j++;
              }
        }
        return ans;
    }
};