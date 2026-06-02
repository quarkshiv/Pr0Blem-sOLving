class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        //landfirst
        int mintime = INT_MAX;
        for(int i=0;i<lst.size();i++){
          int t1=lst[i]+ld[i];
            for(int j=0;j<wst.size();j++){
                int time =t1;
                  if(time>=wst[j])time+=wd[j];
                  else{
                       time+=(wst[j]-time);
                       time+=wd[j];
                  }
                  mintime = min(mintime,time);
            }
              
        }
          //waterfirst
        for(int i=0;i<wst.size();i++){
          int t2=wst[i]+wd[i];
            for(int j=0;j<lst.size();j++){
                int time = t2;
                  if(time>=lst[j])time+=ld[j];
                  else{
                         time+=(lst[j]-time);
                         time+=ld[j];
                  }
                  mintime = min(mintime,time);
            }
              
        }
        return mintime;
    }
};
