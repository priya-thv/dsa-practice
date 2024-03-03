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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        int count=0;
        ListNode*curr=head;
        while(curr!=NULL){
            curr=curr->next;
            count++;
        }
        if(count==1 && n==1){
            return head->next;
        }
        int t=count-n;
        if(t==0)return head->next;
        curr=head;
        for(int i=0;i<t-1;i++){
            curr=curr->next;
        }
        if(curr->next!=NULL){
            curr->next=curr->next->next;
        }
        return head;
    }
};
