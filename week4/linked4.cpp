class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=head,*start=head,*prev=NULL;
        
        for(int i=1;head!=NULL;i++){
            if(i%k==0){
                if(i==k)
                    ans=head;
                else
                    prev->next=head;
                ListNode* nxtNode=start->next,*save=start;
                prev=head->next;
                while(start!=head){
                    start->next=prev;
                    prev=start;
                    start=nxtNode;
                    nxtNode=nxtNode->next;
                }
                head->next=prev;
                prev=save;
                start=nxtNode;
                head=nxtNode;
                continue;
            }
            head=head->next;
        }
        
        return ans;
    }
};
