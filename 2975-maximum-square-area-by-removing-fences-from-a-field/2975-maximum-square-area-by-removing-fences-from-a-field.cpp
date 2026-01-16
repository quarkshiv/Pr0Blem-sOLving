class Solution {
public:
  const int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        long long maxarea=-1;
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_map<long,long>mpp;
        for(int i=0;i<hFences.size();i++){
              for(int j=i+1;j<hFences.size();j++){
                    int diff= hFences[j]-hFences[i];
                      mpp[diff]++;
              }
        }
         for(int i=0;i<vFences.size();i++){
              for(int j=i+1;j<vFences.size();j++){
                 long long diff=vFences[j]-vFences[i];
                    if(mpp.count(diff)){
                    long long area=diff*diff;
                        maxarea=max(maxarea,area);     
                    }
              }
         }
         if(maxarea==-1){
              return -1;
         }
         else return maxarea%mod;
    }
};