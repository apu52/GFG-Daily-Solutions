class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if(head==NULL||head->next==head){
            return head;
        }
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        do{
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }while(curr!=head);
        head->next=prev;
        head=prev;
        return head;
        
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if(head==NULL){
            return NULL;
        }
        if(head->data==key){
            if(head->next==head){
                delete head;
                return NULL;
            }
            Node* last=head;
            while(last->next!=head){
                last=last->next;
            }
            last->next=head->next;
            Node* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        Node* prev;
        Node* curr=head;
        while(curr->next!=head){
            if(curr->data==key){
                prev->next=curr->next;
                delete curr;
                return head;
            }
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};
