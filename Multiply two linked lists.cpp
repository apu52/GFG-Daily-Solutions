class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1 = 0, num2 = 0;
        const int MOD = 1000000007;
        while (first != NULL) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }
        while (second != NULL) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }
        return (num1 * num2) % MOD;
    }
};
