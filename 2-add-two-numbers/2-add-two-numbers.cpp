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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int cry = 0;
        
        ListNode* head = NULL;
        ListNode* resTail = NULL;
        
        while(cur1 and cur2){
            int curVal = cur1->val + cur2->val;
            curVal += cry;
            
            if(curVal > 9){
                cry = 1;
                curVal %= 10;
            }
            else cry = 0;
            
            if(head == NULL){
                head = new ListNode(curVal);
                resTail = head;
            }   
            else{
                resTail->next = new ListNode(curVal);
                resTail = resTail->next;
            }
            
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        if(cur1){
            remNodeAdder(resTail, cur1, cry);
        }
        if(cur2){
            remNodeAdder(resTail, cur2, cry);
        }
        
        
        if(cry){
            resTail->next = new ListNode(1);
        }
        
        return head;
    }
    
    void remNodeAdder(ListNode* &resTail, ListNode* cur, int &cry){
        while(cur){
            int curVal = cur->val + cry;
            if(curVal > 9){
                cry = 1;
                curVal %=10;
            }
            else cry = 0;
            resTail->next = new ListNode(curVal);
            resTail = resTail->next;
            cur = cur->next;
        }
        
    }
};