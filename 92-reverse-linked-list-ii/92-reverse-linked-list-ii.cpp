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
    ListNode* reverseBetween(ListNode* args, int left, int right) {
        
        if(left == right) return args;
        
        ListNode* head = new ListNode(-1);
        head->next = args;
        
        ListNode* ptr = head, *prev = head;
        
        ListNode* next = head->next, *curr = head;
        
        int t = left + 1;
        
        while(t > 1) {
            ptr = ptr->next;
            if(t > 2) prev = prev->next;
            next = next->next;
            curr = curr->next;
            t--;
        }
        
        int cnt = right - left;
        
        while(cnt > 0 and next){
            ListNode* temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
            cnt--;
        }
        
        prev->next = curr;
        ptr->next = next;
        
        return head->next;
    }
};