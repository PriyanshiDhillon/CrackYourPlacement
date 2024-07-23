class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        const long long MOD = 1000000007;

        Node* temp = first;
        long long num1 = 0;
        while(temp != nullptr) {
            num1 = (num1 * 10 + temp->data) % MOD;
            temp = temp->next;
        }

        temp = second;
        long long num2 = 0;
        while(temp != nullptr) {
            num2 = (num2 * 10 + temp->data) % MOD;
            temp = temp->next;
        }

        return (num1 * num2) % MOD;
    }
};