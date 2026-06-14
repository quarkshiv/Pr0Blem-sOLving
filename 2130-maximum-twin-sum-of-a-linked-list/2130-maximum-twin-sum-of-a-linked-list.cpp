/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if(!head)return 0;
         ListNode* temp = head;
         vector<int>arr;

         while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
         }
            int  n  =arr.size();
            int maxi =0;
            int l=0;
            int r=n-1;
            while(l<r){
                 int sum = arr[l]+arr[r];
                 maxi = max(maxi,sum);
                 l++;
                 r--;
            }     
            return maxi;
    }
};