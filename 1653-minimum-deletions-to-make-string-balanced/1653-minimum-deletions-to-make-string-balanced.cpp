class Solution {
public:
    int minimumDeletions(string s) {
        int  n =s.size();
        vector<int>prefb(n,0);
        prefb[0]=(s[0]=='b');
          for (int i = 1; i < n; i++) {
            prefb[i] = prefb[i-1]+(s[i]=='b');
        }
         vector<int>suffa(n, 0);
        suffa[n-1] =(s[n-1]=='a');
        for (int i=n-2;i>=0;i--) {
            suffa[i]=suffa[i+1]+(s[i]=='a');
        }
           int del= n;

        for (int i=0;i<n-1;i++) {
            del= min(del, prefb[i]+suffa[i + 1]);
        }
        del= min(del,prefb[n - 1]);
        del = min(del,suffa[0]);

        return del;

    }
};
