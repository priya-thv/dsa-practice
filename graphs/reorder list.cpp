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
    void reorderList(ListNode* head) {
        if(head==NULL || !head->next || !head->next->next)return;
        int size=0;
        ListNode* head2=head;
        ListNode* head1=head;
        while(head1!=NULL){
            size++;
            head1=head1->next;
        }
        size=size/2;
        cout<<size;
        head1=head;
        for(int i=0;i<size;i++){
            head1=head1->next;
        }

        head2=head1->next;
        head1->next=NULL;
        ListNode*curr=head2;
        ListNode*next=NULL;
        ListNode*preve=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=preve;
            preve=curr;
            curr=next;
        }
        ListNode*t=NULL;
        ListNode*f=NULL;
        ListNode* first = head;
        ListNode* second = preve;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
