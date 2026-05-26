class Solution {
public:
    bool canCross(vector<int>& stones) {
         if(stones[0]!=0 || stones[1]!=1)return false;
        unordered_set<int>st(stones.begin(),stones.end());
        set<string>vis;
         vis.insert("1#1");
        queue<pair<int,int>>q;
        q.push({1,1});
        while(!q.empty()){
            int stone = q.front().first;
              int k = q.front().second;
              q.pop();
              if(stone==stones.back())return true;
              for(int nxt = k-1;nxt<=k+1;nxt++){
                  int newpos = stone+nxt;
                  string state = to_string(newpos) + "#"+ to_string(nxt);
                  if(st.contains(newpos) && !vis.contains(state)){
                        vis.insert(state);
                        q.push({newpos,nxt});
                  }
              }

        }
        return false;
    }

};