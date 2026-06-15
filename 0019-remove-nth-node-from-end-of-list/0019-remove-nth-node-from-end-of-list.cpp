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
ListNode* rev(ListNode* head){
       ListNode* prev= nullptr;
       ListNode* curr= head;
       while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev =  curr;
            curr=nxt;
       }
       return prev;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;
               ListNode* newhead = rev(head);
               if(n==1){
                 ListNode* temp  = newhead;
                 newhead =newhead->next;
                 delete temp; 
               }
               else{
                   ListNode* temp  = newhead;
                      for(int i=1;i<n-1;i++){
                            temp = temp->next;
                      }
                      ListNode* del = temp->next;
                      temp->next=del->next;
                      delete del;
                      
               }
               head = rev(newhead);
               return head;
    }
};