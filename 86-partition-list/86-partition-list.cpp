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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        
        ListNode* node = new ListNode(INT_MIN);
        node->next = head;
        
        int cnt = 0;
        
        ListNode* tail = head;
        while(tail->next != NULL){
            if(tail->val >= x) cnt++;
            tail = tail->next;
        }
        
        if(tail->val >= x) cnt++;
        
        ListNode* itr = node;
        
        while(cnt > 0){
            
            if(itr->next->val >= x){
                tail->next = new ListNode(itr->next->val);
                tail = tail->next;
                
                itr->next =  itr->next->next;
                
                cnt--;
            }else itr = itr->next;
            
        }
        
        return node->next;
    }
};