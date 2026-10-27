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
    ListNode* del_next(ListNode* head){
        ListNode* temp = head->next;
        head->next = temp->next;
        delete temp;
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *t1=head;
        while(t1 && t1->next){
            if(t1->val==t1->next->val){
                t1 = del_next(t1);
            }else{
                t1=t1->next;
            }
        }
        return head;
    }
};