class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        for (int targetSign : {1, -1}) {
            vector<int> temp = nums; 
            int oper = 0;

            for (int i = 0; i + 1 < n; ++i) {
                if (temp[i] != targetSign) {
        
                    temp[i] *= -1;
                    temp[i + 1] *= -1;
                    oper++;

                    if (oper > k) break; 
                }
            }

            if (oper <= k && temp[n - 1] == targetSign) {
                return true;
            }
        }

        return false;
    }
};
