class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        for(auto it : aliceSizes){
            for(auto ut : bobSizes){
                if(sumA - it +ut==sumB-ut+it){
                    return{it,ut};
                }
            }
        }
        return {};
    }
};