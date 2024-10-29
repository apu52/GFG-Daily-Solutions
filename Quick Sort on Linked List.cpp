class Solution {
  public:
    struct Node* findTail(struct Node* head){
        struct Node* tail = head;
        
        while(head != NULL){
            tail = head;
            head = head->next;
        }
        return tail;
    }
    struct Node* partition(struct Node* head,struct Node* tail){
        struct Node* pivot = head;
        
        struct Node* pre = head;
        struct Node* curr = head;
        
        while(curr != tail->next){
            if(curr->data < pivot->data){
                swap(pre->next->data,curr->data);
                pre = pre->next;
            }
            curr = curr->next;
        }
        swap(pivot->data,pre->data);
        
        return pre;
    }
    void quickSortOG(struct Node* head,struct Node* tail){
        if(head == NULL || head == tail){
            return;
        }
        
        struct Node* pivot = partition(head,tail);
        
        quickSortOG(head,pivot);
        quickSortOG(pivot->next,tail);
    }
    struct Node* quickSort(struct Node* head) {
        struct Node* tail = findTail(head);
        quickSortOG(head,tail);
        return head;
    }
};
