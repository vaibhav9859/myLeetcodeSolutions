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
    ListNode* reverseList(ListNode* head) {
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* third = new ListNode(0);

        
        second->next = head;
        if(second->next) third->next = second->next->next;

        while(second->next){
            second->next->next = first->next;;

            first->next = second->next;
            second->next = third->next;
            if(third->next) third->next = third->next->next;
        }

        return first->next;
    }
};