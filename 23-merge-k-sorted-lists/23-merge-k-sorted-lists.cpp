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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) return NULL;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        
        ListNode* myHead = NULL;
        
        int sz = lists.size();
        for(int i=0; i<sz; i++){
            if(lists[i] != NULL) minHeap.push({lists[i]->val, lists[i]});
        }
        
        if(minHeap.size() >= 1) myHead = minHeap.top().second;
        
        // cout<<myHead->val<<endl;
        // return NULL;
        
        
        ListNode* prev = NULL;
        ListNode* cur = NULL;
        
        while(minHeap.empty() != 1){
            if(cur==NULL){
                cur = minHeap.top().second;
                minHeap.pop();
                if(cur->next != NULL) minHeap.push({cur->next->val, cur->next});
                
                cur->next = NULL;
            }
            else{
                prev = cur;
                cur = minHeap.top().second;
                minHeap.pop();
                if(cur->next != NULL) minHeap.push({cur->next->val, cur->next});
                
                cur->next = NULL; 
                
                prev->next = cur;
            }
        }
        
        // prev->next = NULL;
        return myHead;
    }
};