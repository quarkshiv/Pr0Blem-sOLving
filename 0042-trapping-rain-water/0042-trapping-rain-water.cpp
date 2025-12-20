class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pref(n+1,0),suff(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=max(pref[i-1],height[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=max(suff[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
           int val = (min(suff[i+1],pref[i+1]) -height[i]);
           if(val>0){
            ans+=val;
           }
        }
        return ans;
    }
};