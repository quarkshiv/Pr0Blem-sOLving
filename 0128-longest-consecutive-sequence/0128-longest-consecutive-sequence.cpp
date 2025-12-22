class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        int maxcnt=1;
        for(auto it :st){
            if(!st.count(it-1)){
                  int cnt=1;
                  int x=it;
                  while(st.count(x+1)){
                    cnt++;
                    x++;
                  }
                  maxcnt= max(cnt,maxcnt);     
            }
        }
        return maxcnt;
    }
};