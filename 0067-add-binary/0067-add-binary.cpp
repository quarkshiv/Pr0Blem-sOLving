class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int ans=0;
        int i=0;
        int j=0;
        string res="";
        int carry=0;
         while(i<a.size() || j<b.size() || carry){
            int x=0;
            int y=0;
            if (i<a.size()) x = a[i] -'0';
            if (j< b.size()) y = b[j] -'0';
            ans = x + y+ carry;
            res += char((ans%2) + '0');
            carry = ans/2;
             i++;
             j++;
         }
        reverse(res.begin(),res.end());
        return res;
    }
};