/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p=head;
        unordered_map <ListNode*,int> list;
        while(p!=nullptr){
            if(list.count(p)==0){
                ListNode *newNode=p;
                list[newNode]=1;
            }
            else if(list.count(p)==1){
                return true;
            }
            p=p->next;
        }
        return false;
    }
};