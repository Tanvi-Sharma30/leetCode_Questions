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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode dummy1 (0);
        ListNode dummy2 (0);

        ListNode* lowTail = &dummy1;
        ListNode* highHead = &dummy2;
        ListNode* highTail = &dummy2;

        ListNode*curr = head;
        while(curr!=NULL){
            ListNode* nextNode = curr->next;
            curr->next = NULL;
            if(curr->val<x){
                lowTail->next=curr;
                lowTail=curr;
            } else {
                highTail->next = curr;
                highTail = curr;
            }
            curr = nextNode;
        }
        lowTail->next = highHead->next;
        highTail->next = NULL;
        return dummy1.next;
    }
};