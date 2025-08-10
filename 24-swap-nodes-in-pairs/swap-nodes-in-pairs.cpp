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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead=head->next;
        ListNode* current = head;
        ListNode* prev = nullptr;

        while(current&&current->next){
        ListNode* nxt = current->next;
        ListNode* after = nxt->next;  
        nxt->next = current;
        current->next = after;
        if (prev) prev->next = nxt;
        
        prev = current;
        current = after;          
        }
        return newHead;
    }
};