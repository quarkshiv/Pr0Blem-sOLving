class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        long long cnt = 0;

        for(int i = 0; i < n; i++) {
            long long sum = 0;

            for(int j = i; j < n; j++) {
                sum += nums[j];

                long long t = llabs(sum);
                int last = t % 10;
                while(t >= 10)
                    t /= 10;
                int first = t;
                if(first == x && last == x)
                    cnt++;
            }
        }

        return cnt;
    }
};