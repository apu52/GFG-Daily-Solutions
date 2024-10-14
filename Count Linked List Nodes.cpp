class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        // Initialize the count to 0
        int count = 0;
        
        // Traverse the linked list
        struct Node* current = head;
        while (current != NULL) {
            count++; // Increment count for each node
            current = current->next; // Move to the next node
        }
        
        // Return the total count of nodes
        return count;
    }
};
