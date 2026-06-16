class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        for(auto it : arr){
             mpp[it]++;
        }
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto it : mpp){ 
                pq.push(it.second);
        }
        while(k-- && !pq.empty()){
            int val= pq.top();
            val--;
              pq.pop();
              if(val>0)pq.push(val);
        }
        return pq.size();
    }
};