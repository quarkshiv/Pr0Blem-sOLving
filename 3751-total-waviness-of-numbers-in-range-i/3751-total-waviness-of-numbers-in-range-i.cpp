class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
           for(int j=num1;j<=num2;j++){
                  string s = to_string(j);
                  if(s.size()<3)continue;
                  int peak=0;
                  int valley=0;
                  for(int i=1;i+1<s.size();i++){
                      if(s[i]>s[i-1] && s[i]>s[i+1])peak++;
                         if(s[i]<s[i-1] && s[i]<s[i+1])valley++;
                  }
                  ans+=peak+valley;
           }
           return ans;
    }
};