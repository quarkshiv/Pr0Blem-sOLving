class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int l=0;
        int m= piles.size()-2;
        int ans=0;
        while(l<m){
            ans+=piles[m];
            m-=2;
            l++;
        }
        return ans;
    }
};