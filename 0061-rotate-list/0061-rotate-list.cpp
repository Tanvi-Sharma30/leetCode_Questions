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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL|| k==0) return head;
        ListNode* temp = head;
        int len=1;
        while(temp->next!=NULL){ 
            len+=1;
            temp=temp->next;
        }
        k = k%len;
        temp->next = head;
        temp = head;
        for(int i=1;i<len-k;i++){
            temp=temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next=NULL;

        return newHead;
    }
};