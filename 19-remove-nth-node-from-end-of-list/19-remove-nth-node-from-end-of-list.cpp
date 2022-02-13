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
        ListNode* b = head;
        
        // if(head->next == NULL and n == 1) return NULL;
        
        for(int i=0; i<n; i++){
            f = f->next;
        }
        
        if(!f){
            head = head->next; return head;
        }
        
        while(f->next != NULL){
            b = b->next;
            f = f->next;
        }
        b->next = b->next->next;
        
        return head;
    }
};