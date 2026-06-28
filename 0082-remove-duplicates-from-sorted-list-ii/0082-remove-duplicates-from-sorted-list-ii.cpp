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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL|| head->next==NULL)  return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while(curr!=NULL){
            if(curr->next!=NULL && curr->val == curr->next->val){
                ListNode* temp=curr;
                curr=curr->next;
            while(curr!=NULL && curr->val ==temp->val){
                ListNode* del=curr;
                curr=curr->next;
               delete(del);
            }
               delete(temp);
               prev->next=curr;
        } else{
            
            prev->next = curr;
            prev= curr;
            curr= curr->next;
            }
        }
        return dummy.next;
    }
};