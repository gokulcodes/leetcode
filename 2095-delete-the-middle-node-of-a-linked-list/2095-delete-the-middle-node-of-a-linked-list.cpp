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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        
        ListNode* node = head;
        ListNode* slow = node, *fast = node;
        
        while(fast and fast->next){
            fast = fast->next;
            if(fast->next and fast->next->next){
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        slow->next = slow->next->next;
        
        // cout << slow->val <<" " << fast->val << endl;
        
        return node;
    }
};