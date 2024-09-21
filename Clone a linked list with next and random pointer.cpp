class Solution {
  public:
  
    Node* find(Node* curr1, Node* curr2, Node *x)
    {
        if(x==NULL)
        return NULL;
        
        while(curr1!=x)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return curr2;
    }
  
    Node *copyList(Node *head) {
        // Write your code here
        
        Node *headcopy = new Node(0);
        Node *tailcopy = headcopy;
        Node *temp = head;
        
        while(temp)
        {
            tailcopy->next = new Node(temp->data);
            tailcopy = tailcopy->next;
            temp = temp->next; 
        }
        
        tailcopy = headcopy;
        headcopy = headcopy->next;
        delete tailcopy;
        
        
        tailcopy = headcopy;
        temp = head;
        
        while(temp)
        {
            tailcopy->random = find(head,headcopy,temp->random);
            tailcopy = tailcopy->next;
            temp = temp->next;
        }
        
        return headcopy;
    }
};
