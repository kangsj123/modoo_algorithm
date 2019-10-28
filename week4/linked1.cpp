class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current=head;
        
        if(current!=NULL && current->next!=NULL)
            head=current->next;
        
        while(current!=NULL && current->next!=NULL){
            ListNode* nextNode=current->next;
            
            current->next=nextNode->next;
            nextNode->next=current;
            
            ListNode* save=current;
            current=current->next;
            
            if(current!=NULL && current->next!=NULL)
                save->next=current->next;
        }
        
        return head;
    }
};
