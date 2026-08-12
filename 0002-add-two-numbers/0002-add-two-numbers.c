/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    struct ListNode *temp1=l1,*temp2=l2,*new=NULL,*l3=NULL,*temp3=NULL;
    while (temp1!=NULL && temp2!=NULL){
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->next=NULL;
        if (l3==NULL){
            l3=new;
            temp3=new;
        }else{
            temp3->next=new;
            temp3=new;
        }
        if(temp1->val+temp2->val+carry<10){
            temp3->val=temp1->val+temp2->val+carry;
            carry=0;
        }else{
            temp3->val=(temp1->val+temp2->val+carry)%10;
            carry=1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL){
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->next=NULL;
        temp3->next=new;
        temp3=new;
        temp3->val=(temp1->val+carry)%10;
        if(temp1->val+carry>=10){
            carry=1;
        }else{
            carry=0;
        }
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->next=NULL;
        temp3->next=new;
        temp3=new;
        temp3->val=(temp2->val+carry)%10;
        if(temp2->val+carry>=10){
            carry=1;
        }else{
            carry=0;
        }
        temp2=temp2->next;
    }
    if(carry==1){
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->next=NULL;
        temp3->next=new;
        temp3=new;
        temp3->val=carry;
    }
    return l3;
}