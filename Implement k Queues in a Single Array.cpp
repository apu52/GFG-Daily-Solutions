class kQueues {
private:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;
    int n, k;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize queues as empty
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize free list
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    // Enqueue x into i-th queue
    void enqueue(int x, int i) {
        if (freeSpot == -1) return; // array full

        int index = freeSpot;
        freeSpot = next[index];

        arr[index] = x;

        if (front[i] == -1) {
            front[i] = index;
        } else {
            next[rear[i]] = index;
        }

        next[index] = -1;
        rear[i] = index;
    }

    // Dequeue from i-th queue
    int dequeue(int i) {
        if (front[i] == -1) return -1; // empty queue

        int index = front[i];
        front[i] = next[index];

        if (front[i] == -1) {
            rear[i] = -1;
        }

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // Check if i-th queue is empty
    bool isEmpty(int i) {
        return front[i] == -1;
    }

    // Check if array is full
    bool isFull() {
        return freeSpot == -1;
    }
};
