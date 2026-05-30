class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini=arr[0];
        int maxprofit=0;
        for(int i=1;i<arr.size();i++){
               int profit = arr[i]-mini;
               maxprofit = max(profit,maxprofit);
               mini = min(mini,arr[i]);
        }
        return maxprofit;
    }
};