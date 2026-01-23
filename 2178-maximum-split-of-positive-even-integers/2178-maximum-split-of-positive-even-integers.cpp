class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};
        long long sum=0;
        long long val=2;
        vector<long long>v;
        while(sum+val<=finalSum){
               sum+=val;
               v.push_back(val);
               val+=2;
        }
        long long left= finalSum-sum;
        if(left>0) v[v.size()-1]+=left;
        return v;
    }
};