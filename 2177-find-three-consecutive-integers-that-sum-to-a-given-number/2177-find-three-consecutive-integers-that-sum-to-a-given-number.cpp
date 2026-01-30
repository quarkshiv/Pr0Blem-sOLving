class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>v;
        long long val = (num-3)/3;
            if(val + (val+1)+ (val+2)==num){
                  v.push_back(val);
                  v.push_back(val+1);
                  v.push_back(val+2);
            }
          return v;
    }
};