class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
          sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int r=0;
        for(auto it : houses){
            int low = 0;
            int high = heaters.size()-1;
            while(low<=high){
                    int mid  = (low + high)/2;
                    if(heaters[mid]<it){
                        low = mid+1;
                    }
                    else{
                        high=mid-1;
                    }

            }
             int dist = INT_MAX;
            if (low < heaters.size()){
             dist = abs(heaters[low] -it);
        }
            if(low>0){
                dist = min(dist,abs(heaters[low-1] - it));
            }
                  r = max(r,dist);
        }
        return r;
        
    }
};