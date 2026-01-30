class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways_p=total/cost1;
        int temp=total;
        long long ans=0;
        for(int i=0;i<=ways_p;i++){
               temp-=(i*cost1);
               if(temp==0)ans++;
               if(temp>0){
                  ans+=((temp/cost2)+1);
               }
               temp=total;
        }
        return ans;
    }
};