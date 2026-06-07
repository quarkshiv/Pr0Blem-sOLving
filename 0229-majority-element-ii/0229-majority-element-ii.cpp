class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int ele1=INT_MAX;
        int ele2=INT_MAX; 
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<v.size();i++){
             if(cnt1==0 && v[i]!=ele2){
                   cnt1=1;
                   ele1= v[i];
             }
             else if(cnt2==0 && v[i]!=ele1){
                   cnt2=1;
                   ele2= v[i];
             }
             else if(v[i]==ele1)cnt1++;
              else if(v[i]==ele2)cnt2++;
              else{
                cnt1--;
                cnt2--;
              }
        }
        //recheck karo taaki pata chal jaaye ki exist bhi karte h ki nhi
        cnt1=0;
        cnt2=0;
        for(int i=0;i<v.size();i++){
             if(v[i]==ele1)cnt1++;
             if(v[i]==ele2)cnt2++;
        }
        int mini = v.size()/3 + 1;
    set<int>st;
        if(cnt1>=mini)st.insert(ele1);
          if(cnt2>=mini)st.insert(ele2);
          vector<int>ans(st.begin(),st.end());
          return ans;
    }
};