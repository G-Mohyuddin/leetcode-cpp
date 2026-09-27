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
        ListNode *fast=head,*slow=head,*temp1,*temp2;
        while(fast!=NULL &&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=fast;
        fast=NULL;
        while(slow!=NULL){
            temp1=slow->next;
            slow->next=fast;
            fast=slow;
            slow=temp1;
        }
        slow=head;
        while(fast!=NULL && slow!=NULL){
            temp1=fast->next;
            temp2=slow->next;
            slow->next=fast;
            slow=temp2;
            fast->next=slow;
            fast=temp1;
        }
    }
};