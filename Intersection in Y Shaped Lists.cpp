class Solution {
  public:
    int count(Node* head){
        int cnt=0;
        Node* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* t1=head1;
        Node* t2=head2;
        
        int cnt1=count(t1);
        int cnt2=count(t2);
        
        if(cnt1>cnt2) {
            while(t1){
                cnt1--;
                t1=t1->next;
                if(cnt1==cnt2) break;
            }
        }
        else if(cnt2>cnt1){
            while(t2){
                cnt2--;
                t2=t2->next;
                if(cnt1==cnt2) break;
            }
        }
        
        while(t1 && t2){
            if(t1==t2) return t1;
            t1=t1->next;
            t2=t2->next;
        }
        
        return NULL;
    }
};
