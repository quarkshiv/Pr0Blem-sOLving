class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> v1, v2;
        for(int x : nums){
            sum += x;
            if(x % 3 == 1) v1.push_back(x);
            else if(x % 3 == 2) v2.push_back(x);
        }
        if(sum % 3 == 0) return sum;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int rem = sum % 3;
        int ans = 0;
        
        if(rem == 1){
            int op1 = (v1.size() >= 1 ? sum - v1[0] : 0);
            int op2 = (v2.size() >= 2 ? sum - v2[0] - v2[1] : 0);
            ans = max(op1, op2);
        }
        else{ 
            int op1 = (v2.size() >= 1 ? sum - v2[0] : 0);
            int op2 = (v1.size() >= 2 ? sum - v1[0] - v1[1] : 0);
            ans = max(op1, op2);
        }
        
        return ans;
    }
};
