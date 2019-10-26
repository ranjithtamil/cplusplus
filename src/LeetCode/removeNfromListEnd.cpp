/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr;
        int len=0;
       
            curr=head;
            while(curr!=NULL) {
                len++;
                curr=curr->next;
            }
            int idx=len-n+1;     
            curr=head;
            ListNode* prev=curr;
            int i=1;
        
        
            while(curr!=NULL && i<idx) {
                prev=curr;
                curr=curr->next;
                i++;
            }
        
        
            if(prev->next!=NULL) {
                if(i==1) {      //if i is the first element to be removed, Update head to next element.
                    head=head->next;
                }
                else {
                    prev->next=prev->next->next;    // remove element by skipping one node. Normal case.
                }
            }
            else {
                head=NULL;  //if prev->next==NULL, it means that there is only one element.prev=curr, and i==idx. while loop was skipped in this case
            }            
        return head;
    }
};
