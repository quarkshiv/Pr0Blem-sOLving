class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
        string ans="";
        while(!pq.empty()){
              int val1  =pq.top().first;
              char c1= pq.top().second;
              pq.pop();
             int n=ans.size();
             if(n>=2 && ans[n-1]==c1 && ans[n-2]==c1){
                    if(pq.empty())break;
                    int val2 = pq.top().first;
                    char c2= pq.top().second;
                pq.pop();
                ans+=c2;
                val2--;
                if(val2>0)pq.push({val2,c2});
                 pq.push({val1,c1});
             }
             else{
                  ans+=c1;
                  val1--;
                  if(val1>0)pq.push({val1,c1});
             }
        }
        return ans;
    }
};