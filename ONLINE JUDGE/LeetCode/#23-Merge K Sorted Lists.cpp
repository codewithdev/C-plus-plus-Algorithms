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
struct compare {
    bool operator()(
        struct ListNode* a, struct ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
    priority_queue<ListNode*,vector<ListNode*>,compare>pq;
    int k= arr.size();
    for(int i=0;i<k;i++)
        if(arr[i]!=NULL)
            pq.push(arr[i]);
            
        if(pq.empty())
            return NULL;
      ListNode dummy=ListNode(0);
      ListNode*last= &dummy;
      while(!pq.empty()){
          ListNode*curr= pq.top();
          pq.pop();
          last->next= curr;
          last= last->next;
          
          if(curr->next!=NULL)
              pq.push(curr->next);
      }
    return dummy.next;
     }
};
