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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        int len = 2;

        while (prev != NULL && prev->next != NULL) {
            ListNode* curr = prev->next;
            int cnt = 0;
            ListNode* temp = curr;

            // Count nodes in the current group
            while (temp != NULL && cnt < len) {
                cnt++;
                temp = temp->next;
            }

            // Reverse only if the actual group length is even
            if (cnt % 2 == 0) {
                ListNode* groupPrev = temp;
                ListNode* groupCurr = curr;

                for (int i = 0; i < cnt; i++) {
                    ListNode* nextNode = groupCurr->next;
                    groupCurr->next = groupPrev;
                    groupPrev = groupCurr;
                    groupCurr = nextNode;
                }

                prev->next = groupPrev;
                prev = curr;
            } else {
                for (int i = 0; i < cnt; i++) {
                    prev = prev->next;
                }
            }

            len++;
        }

        return head;
    }
};