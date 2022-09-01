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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int count = 0;
        while(cur){
            count++;
            cur = cur->next;
        }
        
        int curPart = 1;
        return reverse(head, k, count/k, curPart);
    }
    
    ListNode* reverse(ListNode* head, int k, int parts, int& curPart){
        if(head == NULL) return head;
        
        if(curPart > parts){
            return head;
        }
        
        int i=0; 
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nxt = NULL;
        
        while(cur and i<k){
            nxt = cur->next;
            cur->next = prev;
            prev=cur;
            cur=nxt;
            i++;
        }
        
        curPart += 1;
        head->next = reverse(cur, k, parts, curPart);
        
        return prev;
    }
};