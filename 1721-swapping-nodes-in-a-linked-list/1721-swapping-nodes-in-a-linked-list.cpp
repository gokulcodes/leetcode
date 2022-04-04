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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node = head, *first = NULL, *last = NULL;
        
        ListNode* ref = node;
        
        int len = 0, temp = k;
        while(node != NULL){
            if(temp - 1 == 0 && first == NULL){
                first = node;
            }
            node = node->next;
            temp--;
            len++;
        }
        
        node = head;
        
        int firstLast = len - k;
        while(node != NULL){
            if(firstLast == 0 and last == NULL){
                last = node;
            }
            node = node->next;
            firstLast--;
        }
        
        // cout << first->val << " " << last->val << endl;
        
        swap(first->val, last->val);
        
        return ref;
    }
};