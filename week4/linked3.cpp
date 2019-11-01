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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0, len2=0;
        ListNode* tmp=l1,*tmp2=l2, *newnode=new ListNode(0);
        while(tmp!=NULL){
            len1++;
            tmp=tmp->next;
        }
        while(tmp2!=NULL){
            len2++;
            tmp2=tmp2->next;
        }
        if(len1<len2){
            swap(l1,l2);
            swap(len1,len2);
        }
        
        addFunc(l1,l2,len1,len2);
        if(l1->val>=10){
            l1->val%=10;
            newnode->next=l1;
            newnode->val=1;
            return newnode;
        }  
        return l1;
        
    }
    void addFunc(ListNode* &first, ListNode* &second, int len1, int len2){
        if(len1==len2){
            if(first->next!=NULL && second->next!=NULL)
                addFunc(first->next,second->next,len1-1,len2-1);
            first->val=first->val+second->val; 
        }
        else
            addFunc(first->next,second,len1-1,len2);
        
        if(first->next!=NULL && first->next->val >=10){
                first->next->val%=10;
                first->val++;
        }     
    }
    
};
