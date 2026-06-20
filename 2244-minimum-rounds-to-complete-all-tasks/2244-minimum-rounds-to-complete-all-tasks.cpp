class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
         unordered_map<int,int>mpp;
        for(auto it : tasks){
             mpp[it]++;
        }
        int op=0;
        for(auto it : mpp){
            if(it.second==1)
        return -1;
              if(it.second%3==0){
                    op+=it.second/3;
              }
              else op+=((it.second/3)+1);
        }
        return op;
    }
};