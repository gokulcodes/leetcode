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
        
        int count = 0, evens = 0;
        
        while(tail->next != NULL){
            count += 1;
            tail = tail->next;
        }
        
        while(evens < count / 2 + ((count + 1) % 2 == 0)){
            
            tail->next = new ListNode(node->next->val);
            tail = tail->next;
            evens++;
            
            node->next = node->next->next;
            node = node->next;
            // cout << evens << " " << count / 2 << endl;
            // cout << tail->val << " " << node->val << " " << first << endl;
            
        }
        
        return head;
    }
};