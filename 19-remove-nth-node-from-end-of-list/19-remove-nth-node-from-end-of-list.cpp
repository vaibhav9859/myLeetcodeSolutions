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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f = head;
        ListNode* s = head;
        
        for(int i=2; i<=n; i++){
            s = s->next;
        }
        
        if(s->next == NULL) return head->next;
        
        while(s->next->next != NULL){
            s = s->next;
            f = f->next;
        }
        
        f->next = f->next->next;
        return head;
    }
};