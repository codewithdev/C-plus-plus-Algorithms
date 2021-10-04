//Problem name: Partition List
//Problem Link: https://leetcode.com/problems/partition-list/

//Code

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      
      //Create two pointer initially at zeroth index.
        ListNode*before= new ListNode(-1);
        ListNode*after= new ListNode(-1);
        ListNode*l1= before;
        ListNode*l2= after;
        ListNode*p= head;
      
      //Find the node which is less than the given index and replace it with the next node.
      //Repeat the steps until the partition is not done.
        while(p!=NULL){
            if(p->val <x)
            {
                l1->next= p;
                l1= l1->next;
                p= p->next;
            }
            else
            {
                l2->next= p;
                l2= l2->next;
                p= p->next;
            }
        }
        l1->next= after->next;
        l2->next= NULL;
        return before->next;
    }
};
