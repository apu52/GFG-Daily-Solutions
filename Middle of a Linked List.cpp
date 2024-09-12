class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        Node* slow= head;
        Node* fast= head;
        if(slow->next==NULL) return slow->data;
        // slow=slow->next;
        // fast= fast->next;
        // fast= fast->next;
        
        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next;
            fast=fast->next;
        }
        
        
        return slow->data;
    }
};
