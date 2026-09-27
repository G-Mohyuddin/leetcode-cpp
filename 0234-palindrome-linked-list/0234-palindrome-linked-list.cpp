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
        ListNode *p1,*p2=head,*p3=head;
        while(p3!=NULL && p3->next!=NULL){
            p3=p3->next->next;
            p2=p2->next;
        }
        p1=p2;
        p3=NULL;
        while(p1!=NULL){
            ListNode *temp=p1->next;
            p1->next=p3;
            p3=p1;
            p1=temp;
        }
        p1=head;
        while(p3!=NULL){
            if(p1->val!=p3->val){
                return false;
            }
            p1=p1->next;
            p3=p3->next;
        }
        return true;
    }
};