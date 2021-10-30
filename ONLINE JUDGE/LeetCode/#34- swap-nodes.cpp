//Problem statement

//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
//Example-

//Input: 1->2->3->4
//Output: 2->1->4->3

//Solution

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
      //Check and replace the node to its next node
        ListNode*a= head;
        ListNode*b= head;
        b= a->next;
        a->next= b->next;
        b->next= a;
        head= b;
      //Swap the node
        a->next= swapPairs(a->next);
        return head;
        
    }
};
