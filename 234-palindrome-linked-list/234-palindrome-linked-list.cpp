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
    ListNode* starter;
    bool isPalindrome(ListNode* head) {
        starter=head;
        return check(head);
    }
    
    bool check(ListNode* head){
        if(head==NULL) return true;
        
        bool val=check(head->next);
        if(val==false) return false;
       
        bool ans = (starter->val == head->val);
        starter = starter->next;
        return ans;
    }                                                               
};