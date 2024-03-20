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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list2==NULL){
            return list1;
        }
        if(list1==NULL){
            return list2;
        }
        ListNode* list=list2;
        while(list->next!=NULL){
            list=list->next;
        }

        ListNode* nextnode;
        ListNode* l=list1;
        int count=0;
        while(l!=NULL){
            count++;
            l=l->next;
        }
        l=list1;
        for(int i=0;i<b;i++){
           l=l->next;
        }
        list->next=l->next;
        l=list1;
        for(int i=0;i<a-1;i++){
           l=l->next;
        }
        l->next=list2;
        return list1;
    }
};
