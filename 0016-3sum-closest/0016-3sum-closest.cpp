class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
      sort(arr.begin(),arr.end());
      int closest=arr[0]+arr[1]+arr[2];
      for(int i=0;i<arr.size();i++){
      int left=i+1;
      int right=arr.size()-1;
      while(left<right){
        int currentsum= arr[i]+arr[right]+arr[left];
        if(abs(currentsum-target)<abs(closest -target)){
            closest = currentsum;
        }
        if(currentsum<target) left++;
        else if(currentsum>target) right--;
        else return currentsum;
      }

      }
      return closest;
    }

};