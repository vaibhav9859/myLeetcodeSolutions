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
    
    void addFirst(ListNode* input, ListNode* &th, ListNode* &tt){
        if(th == NULL){
            th = input; tt = input;
        }
        else{
            input->next = th;
            th = input;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz = 0;
        ListNode* tempHead = head;
        while(tempHead){
            sz++; tempHead = tempHead->next;
        }
        if(sz == 1) return head;
        int times = sz/k;
        
        tempHead = head;
        ListNode* th = NULL; ListNode* tt = NULL;
        
        ListNode* ah=NULL; ListNode* at=NULL;
        
        
        while(times--){
            int tempK = k;
            th = NULL; tt = NULL;
            while(tempK--){
                ListNode* forw = tempHead->next;
                tempHead->next = NULL;
                addFirst(tempHead, th, tt);
                tempHead = forw;
            }
            if(ah == NULL){
                ah = th; at = tt;
            }
            else{
                at->next = th;
                at = tt;
            }
            
        }
        
        at->next = tempHead;
        
        return ah;
    }
};