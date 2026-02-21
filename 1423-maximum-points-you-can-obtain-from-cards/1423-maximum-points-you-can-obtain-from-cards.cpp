class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
               sum+=cardPoints[i];
        }
       int maxsum=sum;
        int r=cardPoints.size()-1;
        int l=k-1;
        while(k--){
            sum-=cardPoints[l];
            l--;
            sum+=cardPoints[r];
            r--;
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};