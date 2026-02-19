class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
       vector<int>pref(n+1,0);
       vector<int>suff(n+1,0);
       for(int i=0;i<nums.size();i++){
           pref[i+1]=pref[i]+ (nums[i]==0);
       }
       for(int i=n-1;i>=0;i--){
          suff[i]=suff[i+1]+(nums[i]==1);
       }
       vector<pair<int,int>>v;
       for(int i=0;i<=n;i++){
              v.push_back({pref[i]+suff[i],i});
       }
       sort(v.rbegin(),v.rend());
       vector<int>ans;
       int maxi=v[0].first;
       int i=0;
       while(i<v.size() && v[i].first==maxi){
                ans.push_back(v[i].second);
                i++;
       }
       return ans;
    }
};