class Solution {
public:
    int reverseBits(int n) {
        string s =  bitset<32>(n).to_string();
        reverse(s.begin(),s.end());
        int ans=0;
        for(auto it: s){
            ans=2*ans+(it-'0');
        }
        return ans;
    }
};