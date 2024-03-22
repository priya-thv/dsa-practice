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
    bool isPalindrome(ListNode* head) {
        vector<int>t;
        ListNode* head1=head;

        while(head1!=NULL){
            t.push_back(head1->val);
            head1=head1->next;
        }
        
        vector<int>r;
         ListNode* h=head;
          ListNode*next=NULL;
          ListNode*preve=NULL;
          ListNode* curr=head;

          while(curr!=NULL){
              next=curr->next;
              curr->next=preve;
              preve=curr;
              curr=next;
          }        
          h=preve;
         while(h!=NULL){
            r.push_back(h->val);
            h=h->next;
        } 
        if(t==r){
            return true;
        }
        return false;
    }
};
