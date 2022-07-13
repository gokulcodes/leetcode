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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        ListNode* node = head;
        ListNode* tail = head;
        
        double count = 0;
        
        while(tail->next != NULL){
            count += 1;
            tail = tail->next;
        }
        
        for(int i = 0; i < ceil(count / 2); i++){
            
            tail->next = new ListNode(node->next->val);
            tail = tail->next;
            
            node->next = node->next->next;
            node = node->next;
            
        }
        
        return head;
    }
};