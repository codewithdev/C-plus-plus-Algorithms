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
        if(head==NULL){
            return NULL;
        }
        ListNode*oddIndex= head;
        ListNode*evenIndex= head->next;
        ListNode*evenHead=evenIndex;
        while(evenIndex!=NULL and evenIndex->next!=NULL){
            oddIndex->next= evenIndex->next;
            oddIndex=oddIndex->next;
            evenIndex->next= oddIndex->next;
            evenIndex= evenIndex->next;
        }
        oddIndex->next= evenHead;
        return head;
    }
};