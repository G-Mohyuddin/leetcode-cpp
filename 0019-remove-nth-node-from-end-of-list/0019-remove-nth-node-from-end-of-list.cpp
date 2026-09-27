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
        ListNode *p1=head,*p2=head;
        for(int i=0;i<n;++i){
            p1=p1->next;
        }
        if(p1==NULL){
            head=head->next;
            delete p2;
            return head;
        }
        while(p1->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }
        p1=p2->next;
        p2->next=p2->next->next;
        delete p1;
        return head;
    }
};