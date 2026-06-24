class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(auto it:s)if(it=='1')cnt++;
        string ans;
        if(cnt==1){
            int len = s.size()-1;
            while(len--)
            ans+='0';
            ans+='1';
            return ans;
        }
            int len = s.size()-cnt;
            int ones=cnt-1;
            while(ones--){
                ans+='1';
            }
            while(len--){
                 ans+='0';
            }
            ans+='1';
            return ans;
    }
};