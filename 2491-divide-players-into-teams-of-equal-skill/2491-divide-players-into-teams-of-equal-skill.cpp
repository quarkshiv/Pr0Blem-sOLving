class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int l=0;
        int r=skill.size()-1;
        sort(skill.begin(),skill.end());
        long long org=skill[l]+skill[r];
        long long ans=0;
    while(l<=r){
        long long check = skill[l]+skill[r];
          long long val = 1LL*skill[l]*skill[r];
          if(check!=org){
            return -1;
          }
          else ans+=val;
          l++;
          r--;
    }
    return ans;
    }
};