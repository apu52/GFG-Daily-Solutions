class Solution {
  public:
    int sumOfLastN_Nodes(struct Node* head, int n) {
        //code here
        if (head == NULL) return 0;

        Node* fast = head;
        Node* slow = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        int sum = 0;
        while (slow != NULL) {
            sum += slow->data;
            slow = slow->next;
        }

        return sum;
    }
};
