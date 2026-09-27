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
    ListNode* rotateRight(ListNode* head, int k) {
        int size=1;
        ListNode *temp=head,*t2;
        if (!head){return NULL;}
        while(temp->next!=NULL){
            temp=temp->next;
            size+=1;
        }
        t2=temp;
        temp->next=head;
        for(int i=0;i<(size-(k%size));++i){
            temp=temp->next;
        }
        t2=temp->next;
        temp->next=NULL;
        return t2;
    }
};