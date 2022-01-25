class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 or !list2){
            if(list1) return list1;
            else return list2;
        }
        ListNode* curPos = NULL;
        ListNode* ans = NULL; int f = 0;
        
        while(list1 and list2){
            if(list1->val <= list2->val){
                if(curPos == NULL){
                    curPos = list1;
                    ans = curPos;
                    list1 = list1->next;
                }
                else{
                    curPos->next = list1;
                    list1 = list1->next;
                }
                
            }
            else{
                if(curPos == NULL){
                    curPos = list2;
                    ans = curPos;
                    list2 = list2->next;
                }
                else{
                    curPos->next = list2;
                    list2 = list2->next;
                }            
            }
            if(f == 0) f = 1;
            else curPos = curPos->next;
        }
        
        if(!list1){
            curPos->next = list2;
        }
        else{
            curPos->next = list1;
        }
        
        return ans;
    }
};