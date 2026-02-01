class RideSharingSystem {
public:
    queue<int> r;
    queue<int> d;
    unordered_map<int,int> mpp; 
    RideSharingSystem(){}
    void addRider(int riderId) {
        r.push(riderId);
        mpp[riderId] = -1;
    }
    void addDriver(int driverId) {
        d.push(driverId);
    }
    vector<int> matchDriverWithRider() {
        while(!r.empty() && mpp.find(r.front()) == mpp.end()){
            r.pop();
        }
        if(r.empty() || d.empty())
            return {-1,-1};
        int x=r.front(); r.pop();
        int y=d.front(); d.pop();
        mpp[x] =y;
        return {y,x};
        
    }

    void cancelRider(int riderId) {
        if(mpp.find(riderId) != mpp.end() && mpp[riderId] == -1){
            mpp.erase(riderId);
        }
    }
};
