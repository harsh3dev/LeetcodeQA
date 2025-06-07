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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* curr = head;
        ListNode* next = head;

        while(next != nullptr && next->next != nullptr){
            curr = curr->next;
            next = next->next->next;
        }

        return curr;
    }
};