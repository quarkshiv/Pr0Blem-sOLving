class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        vector<int>vis(n+1,0);
        for(int i=0;i<m;i++){
            bool valid =false;
            for(int j=1;j<n;j++){
                if(!vis[j-1] && strs[j][i]<strs[j-1][i]){
                    valid=true;
                    ans++;
                    break;
                }
            }
                if(valid) continue;
                 for(int j=1;j<n;j++){
                if(!vis[j-1] && strs[j][i]>strs[j-1][i]){
                    vis[j-1]=1;
                }
                 
            }
        }
        return ans;


    }
};