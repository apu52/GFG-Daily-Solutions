/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *findMid(struct Node* head){
        struct Node *slow=head;
        struct Node *fast=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
      Node * merge(struct Node * left,struct Node * right){
        if(!left) return right;
        if(!right) return left;
        
        Node * cur = NULL,*res = NULL;
        
        if(left->data <= right ->data){
            cur = res = left;
            left = left->next;
        }else{
            cur = res = right;
            right = right->next;
        }
        
        while(left && right){
            if(left -> data < right -> data){
                cur->next = left;
                left->prev = cur;
                cur = left;
                left = left->next; 
            }else{
                cur->next = right;
                right->prev = cur;
                cur = right;
                right = right->next; 
            }
        }
        
        if(left){
            cur ->next = left;
            left->prev = cur;
        }
        if(right){
            cur ->next = right;
            right->prev = cur;
        }
        
        return res;
    }
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        
        struct Node * middle=findMid(head);
        struct Node *first=head;
        
        
        struct Node * second=middle->next;
        middle->next=second->prev=NULL;
        
         first=sortDoubly(first);
          second =sortDoubly(second);
        return merge(first,second);
    }
};


//GFG POTD solution for 27 April
