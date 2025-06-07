/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != prev){
            if(curr->next == NULL || curr->next->next == NULL){
                return false;
            }
            prev = prev->next;
            curr = curr->next->next;
        }

        return true;
    }
};