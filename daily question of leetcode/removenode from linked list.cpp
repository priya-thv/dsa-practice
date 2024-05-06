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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL,*curr=head,*nxt=NULL;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return head=prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
        
        head=reverseList(head);
        ListNode*p=head;
        int max=head->val;
        while(p ->next!= NULL){
            if(p->next->val<p->val){
                p->next=p->next->next;
            }else {
                p=p->next;
            }
            
        }
        head=reverseList(head);
        return head;

    }
};
