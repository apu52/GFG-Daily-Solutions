class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        Node*temp = head;
        Node*prev = nullptr;
        while(temp and k > 0){
            k--;
            prev = temp;
            temp = temp->next;
            if(k==0){
                prev->next = nullptr;
                Node*x = temp;
                if(x==nullptr)return head;
                while(temp and temp->next){
                    temp = temp->next;
                }
                temp->next = head;
                return x;
            }
        }
        return head;
    }
};
