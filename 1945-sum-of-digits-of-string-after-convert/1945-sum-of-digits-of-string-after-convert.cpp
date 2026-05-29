class Solution {
public:
    int getLucky(string s, int k) {
        string t ="";
        for(auto it : s){
             t+=to_string(it-'a'+1);
        }
        
        while(k--){
            int sum=0;
            for(auto it: t){
                  sum= sum + (it-'0');
            }
            t= to_string(sum);
        }
        int sum=0;
        for(int i=0;i<t.size();i++){
            sum=sum+(t[i]-'0');
        }
        return stoi(t);
    }
};