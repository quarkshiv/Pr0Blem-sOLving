class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=0;
        int r=0;
        int n= nums1.size();
        int m= nums2.size();
        int k=0;
        vector<int>ans(n+m);
        while(l<n && r<m){
               if(nums1[l]<=nums2[r]) ans[k++]=nums1[l++];
               else ans[k++]=nums2[r++];
        }
        while(l<n)ans[k++]=nums1[l++];
        while(r<m)ans[k++]=nums2[r++];
        int p = ans.size();
          if(p%2){
               return ans[p/2];
          }
          else return (ans[p/2-1]+ ans[p/2])/2.0;

    }
};