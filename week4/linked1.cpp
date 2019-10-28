class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current=head,*save=NULL;
        
        while(current!=NULL && current->next!=NULL){
            if(current==head)
                head=current->next;
            if(save!=NULL)
                save->next=current->next;
            
            ListNode* nextNode=current->next;
            current->next=nextNode->next;
            nextNode->next=current;
            save=current;
            current=current->next;
        }
        
        return head;
    }
};
