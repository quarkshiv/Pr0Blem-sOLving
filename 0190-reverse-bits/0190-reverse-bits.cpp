class Solution {
public:
    string tobinary(int n){
        string ans="";
        while(n>0){
               ans+=char((n%2) +'0');
               n=n/2;
        }
          reverse(ans.begin(), ans.end());
        while(ans.size() < 32) ans = "0" + ans;
        return ans;
    }
    int reverseBits(int n) {
       string s = tobinary(n);
         reverse(s.begin(),s.end());
        return bitset<32>(s).to_ulong();
    }
};