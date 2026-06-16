class TimeMap {
public:
   unordered_map<string,vector<pair<string,int>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        auto &it = mpp[key];
         int l=0;
         int r= it.size()-1;
         string ans="";
         while(l<=r){
             int mid = (l+r)/2;
             if(it[mid].second<=timestamp){
                 ans=it[mid].first;
                 l=mid+1;
             }
             else{
                r=mid-1;
             }
         }
         return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */