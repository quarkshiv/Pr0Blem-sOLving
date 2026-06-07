class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
           priority_queue<int>pq;
            unordered_map<char,int>mpp;
            for(auto it : tasks){
                 mpp[it]++;
            }
            for(auto it : mpp){
                  pq.push(it.second);
            }
            queue<pair<int,int>>cooldown; //readytime,freq
            int time=0;
            while(!pq.empty() || !cooldown.empty()){
                  time++;
                  if(!cooldown.empty()&&cooldown.front().first==time){
                    pq.push(cooldown.front().second);
                     cooldown.pop();
                  }
                  if(!pq.empty()){
                      int val = pq.top();
                      pq.pop();
                      val--;
                      if(val>0){
                         cooldown.push({time+n+1,val});
                      }
                  }
            } 
            return time;
    }
};