class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int sz=0;
        ListNode* tmp=head;
        while(tmp!=NULL){
            sz++;
            tmp=tmp->next;
        }
        return merge(sz,head);
    }
    ListNode* merge(int sz, ListNode* &head){
        if(sz==0)
            return NULL;
        if(sz==1){
            head->next=NULL;
            return head;
        }
        
        int first_sz=sz/2,second_sz=sz-sz/2;
        ListNode*first,*second,*mergeList,*tmp;
        ListNode* fsave,*ssave;
        tmp=head;
        for(int i=0;i<first_sz;i++)
            head=head->next;
        first=merge(first_sz,tmp);
        second=merge(second_sz,head);

        fsave=first->next;
        ssave=second->next;
        if(first->val<second->val){
            mergeList=first;
            tmp=first;
            first_sz--;
            first=fsave;
        }
        else{
            mergeList=second;
            tmp=second;
            second_sz--;
            second=ssave;
        }
        
        while(first_sz>0 && second_sz>0){
            fsave=first->next;
            ssave=second->next;
            if(first->val<second->val){
                tmp->next=first;
                tmp=first;
                first_sz--;
                first=fsave;
            }
            else{
                tmp->next=second;
                tmp=second;
                second_sz--;
                second=ssave;
            }    
        }
        
        while(first_sz--){
            fsave=first->next;
            tmp->next=first;
            tmp=first;
            first=fsave;
        }
       
        while(second_sz--){
            ssave=second->next;
            tmp->next=second;
            tmp=second;
            second=ssave;
        }
        
        tmp->next=NULL;
        return mergeList;
    }
};
