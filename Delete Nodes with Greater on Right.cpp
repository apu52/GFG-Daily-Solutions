class Solution {
  public:
    Node *compute(Node *head) {
        // code here
          deque<Node*> dq;
    Node* curr = head->next;
    dq.push_back(head);
    
    // Traversing LL
    while(curr) {
        // Condition
        while(!dq.empty() && dq.back()->data < curr->data) {
            dq.pop_back();
        }
        
        dq.push_back(curr);
        curr = curr->next;
    }
    
    // Maintaining head, Last element of LL is always in the queue
    head = dq.front();
    dq.pop_front();
    curr = head;
    
    // Stitching LL
    while(!dq.empty()) {
        curr->next = dq.front();
        dq.pop_front();
        curr = curr->next;
    }
    
    return head;
    }
};
