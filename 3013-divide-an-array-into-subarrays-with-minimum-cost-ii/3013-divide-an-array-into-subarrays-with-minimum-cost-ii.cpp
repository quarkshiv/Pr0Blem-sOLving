class Solution {
public:
    multiset<long long> smallestele;
    multiset<long long> remele;
    long long currsum= 0;
      void addelement(long long val,int k){
            if(smallestele.size()<k-1){
                   smallestele.insert(val);
                   currsum+=val;
            }
            else{
                auto it = smallestele.end();
                        it--;
                        if(val<*it){
                             remele.insert(*it);
                        smallestele.insert(val);
                              currsum+=val;
                               currsum-=(*it);
                               smallestele.erase(it);
                    
                        }
                        else{
                            remele.insert(val);
                        }
            }
      }
      void removeele(long long val,int k){
             auto it = smallestele.find(val);
        if (it != smallestele.end()) {
            smallestele.erase(it);
            currsum-=val;
            if (!remele.empty()) {
                auto i = remele.begin();
                smallestele.insert(*i);
                currsum+=(*i);
                remele.erase(i);
            }
        } else {
            remele.erase(remele.find(val));
        }
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
           if (k == 1) return nums[0]; 
        int n = nums.size();
        for(int i=1;i<=dist+1;i++){
               addelement(nums[i],k);
        }
        long long ans=currsum;
        for(int i=dist+2;i<nums.size();i++){
                addelement(nums[i],k);
                removeele(nums[i-dist-1],k);
                ans = min(ans,currsum);
        }
        return ans+nums[0];
    }
};