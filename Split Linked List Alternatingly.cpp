class Solution {
  public:
    // Function to split a linked list into two lists alternately
    
    vector<Node*> alternatingSplitList(struct Node* head) {
        if(!head->next) return {head, NULL};
        
        Node* head1 = head, *head2 = head->next;
        Node* tail1 = head1, *tail2 = head2;
        
        while(tail2){
            
            tail1->next = tail2->next;
            tail1 = tail1->next;
            
            if(tail1){
                tail2->next = tail1->next;
            }
            tail2 = tail2->next;
        }
        
        return {head1, head2};
    }
};
