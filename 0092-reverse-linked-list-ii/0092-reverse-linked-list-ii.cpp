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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i=1;i<left;i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;
        ListNode* nodeBefRev= prev;
        ListNode* revStartNode = curr;
        for(int i=left;i<=right;i++){
            nextNode= curr->next;
            curr->next=prev;
            prev= curr;
            curr = nextNode;
        }
        nodeBefRev->next = prev;
        revStartNode->next = curr;

        return dummy.next;
    }
};