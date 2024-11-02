class Solution {
public:
    bool isLengthEven(struct Node** head) {
        // If list is empty, consider it even length
        if (*head == NULL)
            return true;
            
        struct Node* temp = *head;
        int count = 0;
        
        // Traverse the linked list and count nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        // Return true if count is even, false otherwise
        return (count % 2 == 0);
    }
};
