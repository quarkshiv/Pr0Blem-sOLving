class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int cnt=0;
            for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=mass){
                mass+=asteroids[i];
                cnt++;
            }
            else break;
        }
        return cnt==asteroids.size();
    }
};