class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        string s = "";
        int rem = 0;

        for(int len = 1; len <= k; len++){
            s.push_back('1');
            rem = (rem * 10 + 1) % k;

            if(rem == 0) return len;
        }

        return -1;
    }
};
