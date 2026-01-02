class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int>mpp;
    for(auto it : nums){
           mpp[it]++;
    }
       vector<int>v;
         for(auto it : mpp){
             v.push_back(it.second);
         }
         if(v.size()==1){
            return v[0];
         }
         sort(v.rbegin(),v.rend());
           bool alleq=true;
           for(int i=1;i<v.size();i++){
              if(v[i]!=v[i-1]){
                  alleq = false;
              }
           }
           if(alleq){
              if(nums.size()%2){
                return 1;
              }
              else return 0;
           }
            int sum=0;
            for(int i=1;i<v.size();i++){
                  sum+=v[i];
            }
            if(v[0]>sum){
                  return v[0]-sum;
            }
            else return (v[0]+sum)%2;

    }
};