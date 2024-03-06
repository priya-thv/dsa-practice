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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next ==NULL || head->next!=NULL && head->next==NULL){
            return false;
        }
         ListNode *fast=head;
        while(head!=NULL && fast!=NULL && fast->next!=NULL ){
            head=head->next;
            fast=fast->next->next;
            if(head==fast){
                return true;
            }
        } 
        return false;
    }
};
