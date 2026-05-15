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
    int getSize(ListNode *head){
        ListNode *temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }

        return size++;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=getSize(headA);
        int sizeB=getSize(headB);
        unordered_map<ListNode*,int> myMap;
        ListNode * temp=headA;
        while(temp){
            myMap[temp]=temp->val;
            temp=temp->next;
        }
        temp=headB;
        for(int i=0;i<sizeB;i++){
            if(myMap.count(temp)){
                return temp;
            }
            myMap[temp]=temp->val;
            temp=temp->next;
        }
        return nullptr;
    }
};