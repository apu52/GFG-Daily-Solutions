class Solution {
  public:
    // function to sort a k sorted doubly linked list
    
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        DLLNode* tail = head;
        DLLNode* nexty = NULL;
        
        int freq = k + 1; 
        
        while(tail && freq > 0){
            pq.push(tail->data);
            
            tail = tail->next;
            nexty = tail;
            freq -= 1;
        }
        
        tail = head;
        
        while(nexty){
            int minVal = pq.top(); pq.pop();
            
            tail->data = minVal;
            tail = tail->next;
            
            pq.push(nexty->data);
            nexty = nexty->next;
        }
        
        while(tail && !pq.empty()){
            int minVal = pq.top(); pq.pop();
            
            tail->data = minVal;
            tail = tail->next;
        }
        
        return head;
    }


};
