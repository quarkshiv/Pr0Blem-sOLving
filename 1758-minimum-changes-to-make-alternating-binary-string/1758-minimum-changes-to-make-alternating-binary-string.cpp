class Solution {
public:
    int minOperations(string& s) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            char ex1 = (i%2) ? '1': '0';
            char ex2 = (i%2) ? '0' : '1';
            if(s[i]!=ex1)cnt1++;
            if(s[i]!=ex2)cnt2++;
        }
        return min(cnt1,cnt2);
    }
};