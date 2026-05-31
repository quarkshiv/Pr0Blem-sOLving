class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long val=mass;
        for(auto it : asteroids){
             if(it>val)return false;
             else{
                val+=it;
             }
        }
        return true;
    }
};