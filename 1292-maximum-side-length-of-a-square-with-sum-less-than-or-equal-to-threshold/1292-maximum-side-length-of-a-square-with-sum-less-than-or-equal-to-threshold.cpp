class Solution {
public:
    bool isPossible(int mid,vector<vector<int>>&prefSum,int threshold){
        int n = prefSum.size()-1;
        int m = prefSum[0].size() - 1;
        for(int i = mid; i <= n; i++){
            for(int j = mid; j <= m; j++){
                int sum = prefSum[i][j]- prefSum[i - mid][j]- prefSum[i][j - mid]
                    + prefSum[i - mid][j - mid];

                if(sum <= threshold) return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>prefSum(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefSum[i][j]=mat[i-1][j-1]+prefSum[i-1][j]+prefSum[i][j-1]-prefSum[i-1][j-1];
            }
        }
        int side=0;
        int low=1,high=min(n,m);
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,prefSum,threshold)){
                side=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return side;
    }
};