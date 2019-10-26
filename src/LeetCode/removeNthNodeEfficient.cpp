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
        ListNode* first=head;
        ListNode* second=head;
        ListNode* prev=head;
//1 2 3 4 5 6         n=2
//1 2                 n=1
//1 2                 n=2
//1                    n=1
        for(int i=1;i<=n && first!=NULL;i++) {
            first=first->next;
        }
        
        while(first!=NULL) {
            prev=second;
            first=first->next;
            second=second->next;
        }
        
        if(prev==head && second==head) {
            head=head->next;
        }
        else if(prev->next!=NULL) {
            prev->next=prev->next->next;    
        }
        
     
        return head;
    }
};
